//
// Created by Antoine Pronnier on 07/01/2025.
//

#include "funixproductions_core/exceptions/ApiBadRequestException.h"

namespace funixproductions_core {

    ApiBadRequestException::ApiBadRequestException(const std::string &message): ApiException(message) {
    }

    ApiBadRequestException::ApiBadRequestException(const std::string &message, const std::string &httpBodyResponse): ApiException(message, httpBodyResponse) {
    }

    ApiBadRequestException::ApiBadRequestException(const std::string &message, const std::exception &cause): ApiException(message, cause) {
    }

    ApiBadRequestException::ApiBadRequestException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause): ApiException(message, httpBodyResponse, cause) {
    }

}