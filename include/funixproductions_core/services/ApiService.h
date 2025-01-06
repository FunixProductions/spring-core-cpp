//
// Created by Antoine Pronnier on 06/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APISERVICE_H
#define FUNIXPRODUCTIONSCORE_APISERVICE_H

#include <nlohmann/json.hpp>
#include "funixproductions_core/dtos/ApiDTO.h"

namespace funixproductions_core {

    template <class T, typename std::enable_if_t<std::is_base_of_v<ApiDTO, T>>>
    class ApiService {
        public:
            ApiService(const std::string &domainUrl, const std::string &path) : domainUrl(domainUrl), path(path) {}

        private:
            const std::string domainUrl;
            const std::string path;
    };
}


#endif //FUNIXPRODUCTIONSCORE_APISERVICE_H
