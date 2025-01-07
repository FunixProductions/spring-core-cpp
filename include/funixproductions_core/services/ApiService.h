//
// Created by Antoine Pronnier on 06/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APISERVICE_H
#define FUNIXPRODUCTIONSCORE_APISERVICE_H

#include <nlohmann/json.hpp>

#include "funixproductions_core/dtos/ApiDTO.h"
#include "funixproductions_core/dtos/PageDTO.h"

namespace funixproductions_core {

    template <class T>
    class ApiService {
    public:
        ApiService(const std::string &domainUrl, const std::string &path);

        const PageDTO<T> findAll(const int &page = 0, const int &elemsPerPage = 300, const std::string &search = "", const std::string &sort = "createdAt:desc") const;
        const T &findById(const std::string &id) const;

        const T &create(const T &dto) const;
        const T &create(const std::list<T> &dtos) const;

        const T &update(const T &dto) const;
        const T &update(const std::list<T> &dtos) const;

        const T &updatePut(const T &dto) const;
        const T &updatePut(const std::list<T> &dtos) const;

        const T &remove(const std::string &dtoId) const;
        const T &remove(const std::list<std::string> &dtosId) const;

    protected:
        const std::string sendRequest(const std::string &method,
                                       const std::string &data,
                                       const std::string &pathToAdd = "",
                                       const std::map<std::string, std::string> &queryParams = {},
                                       const std::map<std::string, std::string> &headers = {}) const;

    private:
        const std::string domainUrl;
        const std::string path;
    };

}

#endif //FUNIXPRODUCTIONSCORE_APISERVICE_H
