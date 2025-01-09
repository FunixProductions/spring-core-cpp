//
// Created by Antoine Pronnier on 07/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APINOTFOUNDEXCEPTION_H
#define FUNIXPRODUCTIONSCORE_APINOTFOUNDEXCEPTION_H

#include "funixproductions_core/exceptions/ApiException.h"

namespace funixproductions_core {

    class ApiNotFoundException: public ApiException {
    public:
        explicit ApiNotFoundException(const std::string &message);

        ApiNotFoundException(const std::string &message, const std::string &httpBodyResponse);

        ApiNotFoundException(const std::string &message, const std::exception &cause);

        ApiNotFoundException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause);
    };

} // funixproductions_core

#endif //FUNIXPRODUCTIONSCORE_APINOTFOUNDEXCEPTION_H
