//
// Created by Antoine Pronnier on 07/01/2025.
//

#include "funixproductions_core/exceptions/ApiForbiddenException.h"

namespace funixproductions_core {

    ApiForbiddenException::ApiForbiddenException(const std::string &message): ApiException(message) {
    }

    ApiForbiddenException::ApiForbiddenException(const std::string &message, const std::string &httpBodyResponse): ApiException(message, httpBodyResponse) {
    }

    ApiForbiddenException::ApiForbiddenException(const std::string &message, const std::exception &cause): ApiException(message, cause) {
    }

    ApiForbiddenException::ApiForbiddenException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause): ApiException(message, httpBodyResponse, cause) {
    }

}