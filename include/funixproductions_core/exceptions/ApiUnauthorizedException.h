//
// Created by Antoine Pronnier on 07/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APIUNAUTHORIZEDEXCEPTION_H
#define FUNIXPRODUCTIONSCORE_APIUNAUTHORIZEDEXCEPTION_H

#include "funixproductions_core/exceptions/ApiException.h"

namespace funixproductions_core {

    class ApiUnauthorizedException: public ApiException {
    public:
        explicit ApiUnauthorizedException(const std::string &message);

        ApiUnauthorizedException(const std::string &message, const std::string &httpBodyResponse);

        ApiUnauthorizedException(const std::string &message, const std::exception &cause);

        ApiUnauthorizedException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause);
    };

} // funixproductions_core

#endif //FUNIXPRODUCTIONSCORE_APIUNAUTHORIZEDEXCEPTION_H
