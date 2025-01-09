//
// Created by Antoine Pronnier on 07/01/2025.
//

#include "funixproductions_core/exceptions/ApiUnauthorizedException.h"

namespace funixproductions_core {

    ApiUnauthorizedException::ApiUnauthorizedException(const std::string &message): ApiException(message) {
    }

    ApiUnauthorizedException::ApiUnauthorizedException(const std::string &message, const std::string &httpBodyResponse): ApiException(message, httpBodyResponse) {
    }

    ApiUnauthorizedException::ApiUnauthorizedException(const std::string &message, const std::exception &cause): ApiException(message, cause) {
    }

    ApiUnauthorizedException::ApiUnauthorizedException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause): ApiException(message, httpBodyResponse, cause) {
    }

} // funixproductions_core