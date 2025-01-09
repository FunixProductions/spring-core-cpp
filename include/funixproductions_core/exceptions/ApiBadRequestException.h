//
// Created by Antoine Pronnier on 07/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APIBADREQUESTEXCEPTION_H
#define FUNIXPRODUCTIONSCORE_APIBADREQUESTEXCEPTION_H

#include "funixproductions_core/exceptions/ApiException.h"

namespace funixproductions_core {

    class ApiBadRequestException : public ApiException {
    public:
        explicit ApiBadRequestException(const std::string &message);

        ApiBadRequestException(const std::string &message, const std::string &httpBodyResponse);

        ApiBadRequestException(const std::string &message, const std::exception &cause);

        ApiBadRequestException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause);
    };

}

#endif //FUNIXPRODUCTIONSCORE_APIBADREQUESTEXCEPTION_H
