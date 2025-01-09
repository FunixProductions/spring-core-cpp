//
// Created by Antoine Pronnier on 07/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APIFORBIDDENEXCEPTION_H
#define FUNIXPRODUCTIONSCORE_APIFORBIDDENEXCEPTION_H

#include "funixproductions_core/exceptions/ApiException.h"

namespace funixproductions_core {

    class ApiForbiddenException: public ApiException {
    public:
        explicit ApiForbiddenException(const std::string &message);

        ApiForbiddenException(const std::string &message, const std::string &httpBodyResponse);

        ApiForbiddenException(const std::string &message, const std::exception &cause);

        ApiForbiddenException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause);
    };

}


#endif //FUNIXPRODUCTIONSCORE_APIFORBIDDENEXCEPTION_H
