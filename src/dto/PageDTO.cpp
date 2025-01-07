//
// Created by Antoine Pronnier on 06/01/2025.
//

#include "funixproductions_core/dtos/PageDTO.h"
#include "funixproductions_core/dtos/ApiDTO.h"

namespace funixproductions_core {

    template <class T>
    PageDTO<T>::PageDTO(): totalPages(0), actualPage(0), totalElementsDatabase(0), totalElementsThisPage(0) {
        static_assert(std::is_base_of<ApiDTO, T>::value, "T must be a subclass of ApiDTO");
    }

    template <class T>
    PageDTO<T>::PageDTO(const std::string &json) {
        static_assert(std::is_base_of<ApiDTO, T>::value, "T must be a subclass of ApiDTO");
        const nlohmann::json jsonObject = nlohmann::json::parse(json);

        this->totalPages = jsonObject["totalPages"].get<int>();
        this->actualPage = jsonObject["actualPage"].get<int>();
        this->totalElementsDatabase = jsonObject["totalElementsDatabase"].get<long>();
        this->totalElementsThisPage = jsonObject["totalElementsThisPage"].get<int>();

        const std::array<std::string, this->totalElementsThisPage> contentJson = jsonObject["content"].get<std::array<std::string, this->totalElementsThisPage>>();
        for (const std::string &jsonFromArray : contentJson) {
            this->content.push_back(T(jsonFromArray));
        }
    }

    template <class T>
    const bool PageDTO<T>::hasNext() const {
        return this->actualPage < this->totalPages;
    }

    template <class T>
    const bool PageDTO<T>::hasPrevious() const {
        return this->actualPage > 1;
    }

    template <class T>
    const long PageDTO<T>::getTotalElementsDatabase() const {
        return this->totalElementsDatabase;
    }

    template <class T>
    const int PageDTO<T>::getTotalPages() const {
        return this->totalPages;
    }

    template <class T>
    const int PageDTO<T>::getActualPage() const {
        return this->actualPage;
    }

    template <class T>
    const int PageDTO<T>::getTotalElementsThisPage() const {
        return this->totalElementsThisPage;
    }

} // funixproductions_core