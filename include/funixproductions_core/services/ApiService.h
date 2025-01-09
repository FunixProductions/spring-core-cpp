//
// Created by Antoine Pronnier on 06/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APISERVICE_H
#define FUNIXPRODUCTIONSCORE_APISERVICE_H

#include <nlohmann/json.hpp>

#include "funixproductions_core/dtos/ApiDTO.h"
#include "funixproductions_core/dtos/PageDTO.h"

#include "funixproductions_core/exceptions/ApiException.h"
#include "funixproductions_core/exceptions/ApiUnauthorizedException.h"
#include "funixproductions_core/exceptions/ApiForbiddenException.h"
#include "funixproductions_core/exceptions/ApiNotFoundException.h"
#include "funixproductions_core/exceptions/ApiBadRequestException.h"

namespace funixproductions_core {

    template <class T>
    class ApiService {
    public:
        ApiService(std::string domainUrl, std::string path);

        const PageDTO<T> findAll(const int &page = 0, const int &elemsPerPage = 300, const std::string &search = "", const std::string &sort = "createdAt:desc") const;
        const T findById(const std::string &id) const;

        const T create(const T &dto) const;
        const T create(const std::list<T> &dtos) const;

        const T update(const T &dto) const;
        const T update(const std::list<T> &dtos) const;

        const T updatePut(const T &dto) const;
        const T updatePut(const std::list<T> &dtos) const;

        void remove(const std::string &dtoId) const;
        void remove(const std::list<std::string> &dtosId) const;

    protected:
        [[nodiscard]] std::string sendRequest(const std::string &method,
                                              const std::string &data,
                                              const std::string &pathToAdd = "",
                                              const std::map<std::string, std::string, std::less<>> &queryParams = {},
                                              const std::map<std::string, std::string, std::less<>> &headers = {}) const;
    private:
        const std::string domainUrl;
        const std::string path;

        std::optional<std::string> bearerToken;
    };

}

#include "ApiService.tpp"

#endif //FUNIXPRODUCTIONSCORE_APISERVICE_H
