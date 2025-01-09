//
// Created by Antoine Pronnier on 09/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_FUNIXBOTUSEREXPERIENCESERVICE_H
#define FUNIXPRODUCTIONSCORE_FUNIXBOTUSEREXPERIENCESERVICE_H

#include "funixproductions_core/services/ApiService.h"
#include "../dtos/FunixBotUserExperienceDTO.h"

namespace funixproductions_core {

    class FunixBotUserExperienceService: public ApiService<FunixBotUserExperienceDTO> {
    public:
        FunixBotUserExperienceService();
    };

} // funixproductions_core

#endif //FUNIXPRODUCTIONSCORE_FUNIXBOTUSEREXPERIENCESERVICE_H
