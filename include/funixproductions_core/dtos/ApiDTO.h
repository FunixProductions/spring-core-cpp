//
// Created by Antoine Pronnier on 04/01/2025.
//

#include <string>
#include <iostream>
#include <optional>
#include <nlohmann/json.hpp>

#ifndef SPRING_CORE_CPP_APIDTO_H
#define SPRING_CORE_CPP_APIDTO_H

namespace funixproductions_core {
    class ApiDTO {
    public:
        /**
         * @brief Default constructor
         */
        ApiDTO() = default;

        /**
         * @brief Constructor
         * @param json
         */
        explicit ApiDTO(const std::string &json);

        virtual ~ApiDTO() = default;

        [[nodiscard]] virtual const std::optional<std::string> &getId() const final;
        virtual void setId(const std::optional<std::string> &id) final;

        [[nodiscard]] virtual const std::optional<std::chrono::system_clock::time_point> &getCreatedAt() const final;
        virtual void setCreatedAt(const std::optional<std::chrono::system_clock::time_point> &createdAt) final;

        [[nodiscard]] virtual const std::optional<std::chrono::system_clock::time_point> &getUpdatedAt() const final;
        virtual void setUpdatedAt(const std::optional<std::chrono::system_clock::time_point> &updatedAt) final;

        /*
         *  Call the superclass toJson to add its fields
            ApiDTO::toJson(json);
         */
        virtual void toJson(nlohmann::json &json) const;

        [[nodiscard]] virtual const std::string convertDateToString(const std::chrono::system_clock::time_point &date) const final;

        [[nodiscard]] virtual const std::chrono::system_clock::time_point convertStringToDate(const std::string &date) const final;

    private:
        std::optional<std::string> id;
        std::optional<std::chrono::system_clock::time_point> createdAt;
        std::optional<std::chrono::system_clock::time_point> updatedAt;
    };
}

#endif //SPRING_CORE_CPP_APIDTO_H
