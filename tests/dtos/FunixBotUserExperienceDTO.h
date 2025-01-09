//
// Created by Antoine Pronnier on 09/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_FUNIXBOTUSEREXPERIENCEDTO_H
#define FUNIXPRODUCTIONSCORE_FUNIXBOTUSEREXPERIENCEDTO_H

#include "funixproductions_core/dtos/ApiDTO.h"

namespace funixproductions_core {

    class FunixBotUserExperienceDTO: public ApiDTO {
    public:
        explicit FunixBotUserExperienceDTO(const std::string &json);
        FunixBotUserExperienceDTO();

        [[nodiscard]] const std::string &getTwitchUserId() const;
        void setTwitchUserId(const std::string &twitchUserId);

        [[nodiscard]] const std::string &getTwitchUsername() const;
        void setTwitchUsername(const std::string &twitchUsername);

        [[nodiscard]] const int &getXp() const;
        void setXp(const int &xp);

        [[nodiscard]] const int &getXpNextLevel() const;
        void setXpNextLevel(const int &xpNextLevel);

        [[nodiscard]] const int &getLevel() const;
        void setLevel(const int &level);

        [[nodiscard]] const long &getLastMessageDateSeconds() const;
        void setLastMessageDateSeconds(const long &lastMessageDateSeconds);

        void toJson(nlohmann::json &json) const override;

    private:
        std::string twitchUserId;
        std::string twitchUsername;
        int xp;
        int xpNextLevel;
        int level;
        long lastMessageDateSeconds;
    };

} // funixproductions_core

#endif //FUNIXPRODUCTIONSCORE_FUNIXBOTUSEREXPERIENCEDTO_H
