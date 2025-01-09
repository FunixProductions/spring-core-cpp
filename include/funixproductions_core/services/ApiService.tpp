//
// Created by Antoine Pronnier on 06/01/2025.
//

#include <curl/curl.h>
#include <sstream>
#include <utility>

#include "ApiService.h"

namespace funixproductions_core {

    template<class T>
    ApiService<T>::ApiService(std::string domainUrl, std::string path) : domainUrl(std::move(domainUrl)), path(std::move(path)) {
        static_assert(std::is_base_of_v<ApiDTO, T>, "T must be a subclass of ApiDTO");

        const char *bearerFromEnv = std::getenv("FUNIXPRODUCTIONS_API_TOKEN");
        if (bearerFromEnv != nullptr) {
            this->bearerToken = std::string(bearerFromEnv);
        }
    }

    template<class T>
    const PageDTO<T> ApiService<T>::findAll(const int &page,
                                             const int &elemsPerPage,
                                             const std::string &search,
                                             const std::string &sort) const {
        return PageDTO<T>(this->sendRequest("GET", "", "", {
                {"page", std::to_string(page)},
                {"elemsPerPage", std::to_string(elemsPerPage)},
                {"search", search},
                {"sort", sort}
        }));
    }

    template<class T>
    const T ApiService<T>::findById(const std::string &id) const {
        return T(this->sendRequest("GET", "", "/" + id));
    }

    template<class T>
    const T ApiService<T>::create(const T &dto) const {
        nlohmann::json json;

        dto.toJson(json);
        return T(this->sendRequest("POST", json.dump()));
    }

    template<class T>
    const T ApiService<T>::create(const std::list<T> &dtos) const {
        nlohmann::json json;

        for (const T &dto : dtos) {
            nlohmann::json subJson;

            dto.toJson(subJson);
            json.push_back(subJson);
        }

        return T(this->sendRequest("POST", json.dump()));
    }

    template<class T>
    const T ApiService<T>::update(const T &dto) const {
        nlohmann::json json;

        dto.toJson(json);
        return T(this->sendRequest("PATCH", json.dump()));
    }

    template<class T>
    const T ApiService<T>::update(const std::list<T> &dtos) const {
        nlohmann::json json;

        for (const T &dto : dtos) {
            nlohmann::json subJson;

            dto.toJson(subJson);
            json.push_back(subJson);
        }

        return T(this->sendRequest("PATCH", json.dump()));
    }

    template<class T>
    const T ApiService<T>::updatePut(const T &dto) const {
        nlohmann::json json;

        dto.toJson(json);
        return T(this->sendRequest("PUT", json.dump()));
    }

    template<class T>
    const T ApiService<T>::updatePut(const std::list<T> &dtos) const {
        nlohmann::json json;

        for (const T &dto : dtos) {
            nlohmann::json subJson;

            dto.toJson(subJson);
            json.push_back(subJson);
        }

        return T(this->sendRequest("PUT", json.dump()));
    }

    template<class T>
    void ApiService<T>::remove(const std::string &dtoId) const {
        this->sendRequest("DELETE", "", {
                {
                        "id", dtoId
                }
        });
    }

    template<class T>
    void ApiService<T>::remove(const std::list<std::string> &dtosId) const {
        std::ostringstream oss;
        for (auto it = dtosId.begin(); it != dtosId.end(); ++it) {
            if (it != dtosId.begin()) {
                oss << ",";
            }
            oss << *it;
        }

        std::string ids = oss.str();

        this->sendRequest("DELETE", "", {
                {
                        "ids", ids
                }
        });
    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    template <class T>
    std::string ApiService<T>::sendRequest(const std::string &method,
                                           const std::string &data,
                                           const std::string &pathToAdd,
                                           const std::map<std::string, std::string, std::less<>> &queryParams,
                                           const std::map<std::string, std::string, std::less<>> &headers) const {
        CURL *curl = curl_easy_init();
        if (!curl) {
            throw ApiException("Curl initialization failed");
        }

        std::string url = this->domainUrl + this->path + pathToAdd;
        if (!queryParams.empty()) {
            url += "?";

            for (const auto &[param, value] : queryParams) {
                url.append(curl_easy_escape(curl, param.c_str(), (int) param.size()))
                        .append("=")
                        .append(curl_easy_escape(curl, value.c_str(), (int) value.size()))
                        .append("&");
            }
            url.pop_back();
        }

        if (method == "POST" || method == "PUT") {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        }

        struct curl_slist* headersToAdd = nullptr;
        for (const auto &[header, value] : headers) {
            headersToAdd = curl_slist_append(
                    headersToAdd,
                    (header + ": " + value).c_str()
            );
        }

        headersToAdd = curl_slist_append(
                headersToAdd,
                "Accept: application/json"
        );
        headersToAdd = curl_slist_append(
                headersToAdd,
                "Content-Type: application/json"
        );
        if (this->bearerToken.has_value()) {
            headersToAdd = curl_slist_append(
                    headersToAdd,
                    ("Authorization: Bearer " + this->bearerToken.value()).c_str()
            );
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headersToAdd);

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        curl_slist_free_all(headersToAdd);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            throw ApiException("Curl request failed. Res status curl: " + std::to_string(res) + "\nRoute: " + url + "\nMethod: " + method + "\nHttpCode: " + std::to_string(http_code) + "\nResponse: " + response);
        } else if (http_code == 401) {
            throw ApiUnauthorizedException("401 Http Server error.\nRoute: " + url + "\nMethod: " + method + "\nResponse: " + response, response);
        } else if (http_code == 403) {
            throw ApiForbiddenException("403 Http Server error.\nRoute: " + url + "\nMethod: " + method + "\nResponse: " + response, response);
        } else if (http_code == 404) {
            throw ApiNotFoundException("Not found Http Server error.\nRoute: " + url + "\nMethod: " + method + "\nResponse: " + response, response);
        } else if (http_code >= 400 && http_code < 500) {
            throw ApiBadRequestException(std::to_string(http_code) + " Http Server error.\nRoute: " + url + "\nMethod: " + method + "\nResponse: " + response, response);
        } else if (http_code >= 500) {
            throw ApiException(std::to_string(http_code) + " Http internal Server error.\nRoute: " + url + "\nMethod: " + method + "\nResponse: " + response, response);
        }

        return response;
    }

}