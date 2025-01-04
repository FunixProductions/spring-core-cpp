//
// Created by Antoine Pronnier on 04/01/2025.
//

#include <string>
#include <iostream>
#include <optional>

#ifndef SPRING_CORE_CPP_APIDTO_H
#define SPRING_CORE_CPP_APIDTO_H

namespace funixproductions_core {
    class ApiDTO {
        public:
            ApiDTO();
            virtual ~ApiDTO();

            const std::optional<std::string> &getId() const;
            void setId(const std::optional<std::string> &id);

            const std::optional<std::chrono::system_clock::time_point> &getCreatedAt() const;
            void setCreatedAt(const std::optional<std::chrono::system_clock::time_point> &createdAt);

            const std::optional<std::chrono::system_clock::time_point> &getUpdatedAt() const;
            void setUpdatedAt(const std::optional<std::chrono::system_clock::time_point> &updatedAt);

        private:
            std::optional<std::string> id;
            std::optional<std::chrono::system_clock::time_point> createdAt;
            std::optional<std::chrono::system_clock::time_point> updatedAt;
    };
}

#endif //SPRING_CORE_CPP_APIDTO_H
