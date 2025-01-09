//
// Created by Antoine Pronnier on 09/01/2025.
//

#include "FunixBotUserExperienceDTO.h"

namespace funixproductions_core {

    FunixBotUserExperienceDTO::FunixBotUserExperienceDTO(const std::string &json): ApiDTO(json) {
        const nlohmann::json jsonObject = nlohmann::json::parse(json);

        if (jsonObject.contains("twitchUserId")) {
            this->twitchUserId = jsonObject["twitchUserId"].get<std::string>();
        }

        if (jsonObject.contains("twitchUsername")) {
            this->twitchUsername = jsonObject["twitchUsername"].get<std::string>();
        }

        if (jsonObject.contains("xp")) {
            this->xp = jsonObject["xp"].get<int>();
        }

        if (jsonObject.contains("xpNextLevel")) {
            this->xpNextLevel = jsonObject["xpNextLevel"].get<int>();
        }

        if (jsonObject.contains("level")) {
            this->level = jsonObject["level"].get<int>();
        }

        if (jsonObject.contains("lastMessageDateSeconds")) {
            this->lastMessageDateSeconds = jsonObject["lastMessageDateSeconds"].get<long>();
        }
    }

    FunixBotUserExperienceDTO::FunixBotUserExperienceDTO(): ApiDTO() {
        this->twitchUserId = "123";
        this->twitchUsername = "twitchUsername-c++";
        this->xp = 0;
        this->xpNextLevel = 100;
        this->level = 1;
        this->lastMessageDateSeconds = 0;
    }

    void FunixBotUserExperienceDTO::toJson(nlohmann::json &json) const {
        json["twitchUserId"] = this->twitchUserId;
        json["twitchUsername"] = this->twitchUsername;
        json["xp"] = this->xp;
        json["xpNextLevel"] = this->xpNextLevel;
        json["level"] = this->level;
        json["lastMessageDateSeconds"] = this->lastMessageDateSeconds;
    }

    const std::string &FunixBotUserExperienceDTO::getTwitchUserId() const {
        return this->twitchUserId;
    }

    void FunixBotUserExperienceDTO::setTwitchUserId(const std::string &twitchUserId) {
        this->twitchUserId = twitchUserId;
    }

    const std::string &FunixBotUserExperienceDTO::getTwitchUsername() const {
        return this->twitchUsername;
    }

    void FunixBotUserExperienceDTO::setTwitchUsername(const std::string &twitchUsername) {
        this->twitchUsername = twitchUsername;
    }

    const int &FunixBotUserExperienceDTO::getXp() const {
        return this->xp;
    }

    void FunixBotUserExperienceDTO::setXp(const int &xp) {
        this->xp = xp;
    }

    const int &FunixBotUserExperienceDTO::getXpNextLevel() const {
        return this->xpNextLevel;
    }

    void FunixBotUserExperienceDTO::setXpNextLevel(const int &xpNextLevel) {
        this->xpNextLevel = xpNextLevel;
    }

    const int &FunixBotUserExperienceDTO::getLevel() const {
        return this->level;
    }

    void FunixBotUserExperienceDTO::setLevel(const int &level) {
        this->level = level;
    }

    const long &FunixBotUserExperienceDTO::getLastMessageDateSeconds() const {
        return this->lastMessageDateSeconds;
    }

    void FunixBotUserExperienceDTO::setLastMessageDateSeconds(const long &lastMessageDateSeconds) {
        this->lastMessageDateSeconds = lastMessageDateSeconds;
    }

} // funixproductions_core
