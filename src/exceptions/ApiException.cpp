//
// Created by Antoine Pronnier on 07/01/2025.
//

#include <nlohmann/json.hpp>

#include "funixproductions_core/exceptions/ApiException.h"

namespace funixproductions_core {

    ApiException::ApiException(const std::string &message): message(message) {}

    ApiException::ApiException(const std::string &message, const std::exception &cause) {
        this->message = message + " caused by " + cause.what();
    }

    ApiException::ApiException(const std::string &message, const std::string &httpBodyResponse): message(message) {
        this->setServerHttpMessage(httpBodyResponse);
    }

    ApiException::ApiException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause) {
        this->message = message + " caused by " + cause.what();
        this->setServerHttpMessage(httpBodyResponse);
    }

    const char *ApiException::what() const noexcept {
        return this->message.c_str();
    }

    const std::optional<std::string> &ApiException::getServerHttpMessage() const {
        return this->serverHttpMessage;
    }

    void ApiException::setServerHttpMessage(const std::string &httpBodyResponse) {
        if (httpBodyResponse.empty()) {
            return;
        }

        nlohmann::json json = nlohmann::json::parse(httpBodyResponse);

        if (json.contains("error")) {
            this->serverHttpMessage = json["error"].get<std::string>();
        }
    }

}
