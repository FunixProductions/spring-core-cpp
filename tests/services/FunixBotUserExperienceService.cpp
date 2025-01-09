//
// Created by Antoine Pronnier on 09/01/2025.
//

#include "./FunixBotUserExperienceService.h"

namespace funixproductions_core {

    FunixBotUserExperienceService::FunixBotUserExperienceService(): ApiService<FunixBotUserExperienceDTO>("https://api.funixgaming.fr", "/funixbot/user/exp") {
    }

} // funixproductions_core