//
// Created by Antoine Pronnier on 06/01/2025.
//

#include <curl/curl.h>
#include "funixproductions_core/services/ApiService.h"

namespace funixproductions_core {

    template<class T>
    ApiService<T>::ApiService(const std::string &domainUrl, const std::string &path) : domainUrl(domainUrl), path(path) {
        static_assert(std::is_base_of<ApiDTO, T>::value, "T must be a subclass of ApiDTO");
    }

    template<class T>
    const T &ApiService<T>::findById(const std::string &id) const {

    }

    template <class T>
    const std::string ApiService<T>::sendRequest(const std::string &method,
                               const std::string &data,
                               const std::string &pathToAdd,
                               const std::map<std::string, std::string> &queryParams,
                               const std::map<std::string, std::string> &headers) const {
        CURL *curl = curl_easy_init();
        if (!curl) {
            throw std::runtime_error("Curl initialization failed");
        }

        std::string url = this->domainUrl + this->path + pathToAdd;
        if (!queryParams.empty()) {
            url += "?";
            for (const std::pair<std::string, std::string> &param : queryParams) {
                url += param.first + "=" + param.second + "&";
            }
            url.pop_back();
        }

        struct curl_slist* headersToAdd = nullptr;
        for (const std::pair<std::string, std::string> &header : headers) {
            headersToAdd = curl_slist_append(headersToAdd, (header.first + ": " + header.second).c_str());
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersToAdd);

        if (method == "POST" || method == "PUT") {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        }

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* ptr, size_t size, size_t nmemb, std::string* data) {
            data->append(ptr, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        curl_slist_free_all(headersToAdd);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            throw std::runtime_error("Curl request failed");
        }

        return response;
    }

}