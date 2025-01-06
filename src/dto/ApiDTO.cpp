//
// Created by Antoine Pronnier on 04/01/2025.
//

#include <sstream>
#include "funixproductions_core/dtos/ApiDTO.h"

namespace funixproductions_core {

    ApiDTO::ApiDTO(const std::string &json) {
        this->fromJson(json);
    }

    const std::optional<std::string> &ApiDTO::getId() const {
        return this->id;
    }

    void ApiDTO::setId(const std::optional<std::string> &id) {
        this->id = id;
    }

    const std::optional<std::chrono::system_clock::time_point> &ApiDTO::getCreatedAt() const {
        return this->createdAt;
    }

    void ApiDTO::setCreatedAt(const std::optional<std::chrono::system_clock::time_point> &createdAt) {
        this->createdAt = createdAt;
    }

    const std::optional<std::chrono::system_clock::time_point> &ApiDTO::getUpdatedAt() const {
        return this->updatedAt;
    }

    void ApiDTO::setUpdatedAt(const std::optional<std::chrono::system_clock::time_point> &updatedAt) {
        this->updatedAt = updatedAt;
    }

    const nlohmann::json ApiDTO::toJson() const {
        nlohmann::json json;

        if (this->id.has_value()) {
            json["id"] = this->id.value();
        }

        if (this->createdAt.has_value()) {
            json["createdAt"] = this->convertDateToString(this->createdAt.value());
        }

        if (this->updatedAt.has_value()) {
            json["updatedAt"] = this->convertDateToString(this->updatedAt.value());
        }

        return json;
    }

    const void ApiDTO::fromJson(const std::string &json) {
        nlohmann::json jsonObject = nlohmann::json::parse(json);

        if (jsonObject.contains("id")) {
            this->id = jsonObject["id"].get<std::string>();
        }

        if (jsonObject.contains("createdAt")) {
            this->createdAt = this->convertStringToDate(jsonObject["createdAt"].get<std::string>());
        }

        if (jsonObject.contains("updatedAt")) {
            this->updatedAt = this->convertStringToDate(jsonObject["updatedAt"].get<std::string>());
        }
    }

    const std::chrono::system_clock::time_point ApiDTO::convertStringToDate(const std::string &date) const {
        std::istringstream dateStream(date);
        std::tm tm = {};

        dateStream >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");

        return std::chrono::system_clock::from_time_t(std::mktime(&tm));
    }

    const std::string ApiDTO::convertDateToString(const std::chrono::system_clock::time_point &date) const {
        std::time_t time = std::chrono::system_clock::to_time_t(date);
        std::tm tm = *std::localtime(&time);

        std::ostringstream dateStream;
        dateStream << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");

        return dateStream.str();
    }

}
