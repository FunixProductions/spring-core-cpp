//
// Created by Antoine Pronnier on 07/01/2025.
//

#include "funixproductions_core/exceptions/ApiNotFoundException.h"

namespace funixproductions_core {

    ApiNotFoundException::ApiNotFoundException(const std::string &message): ApiException(message) {
    }

    ApiNotFoundException::ApiNotFoundException(const std::string &message, const std::string &httpBodyResponse): ApiException(message, httpBodyResponse) {
    }

    ApiNotFoundException::ApiNotFoundException(const std::string &message, const std::exception &cause): ApiException(message, cause) {
    }

    ApiNotFoundException::ApiNotFoundException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause): ApiException(message, httpBodyResponse, cause) {
    }

} // funixproductions_core