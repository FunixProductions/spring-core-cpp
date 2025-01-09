//
// Created by Antoine Pronnier on 06/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_PAGEDTO_H
#define FUNIXPRODUCTIONSCORE_PAGEDTO_H

#include <string>
#include <list>

namespace funixproductions_core {

    template <class T>
    class PageDTO {
        public:
            PageDTO();

            explicit PageDTO(const std::string &json);

            [[nodiscard]] const std::list<T> &getContent() const;

            [[nodiscard]] bool hasNext() const;
            [[nodiscard]] bool hasPrevious() const;

            [[nodiscard]] const long &getTotalElementsDatabase() const;
            [[nodiscard]] const int &getTotalPages() const;
            [[nodiscard]] const int &getActualPage() const;
            [[nodiscard]] const int &getTotalElementsThisPage() const;

        private:
            std::list<T> content;
            int totalPages;
            int actualPage;
            long totalElementsDatabase;
            int totalElementsThisPage;
    };

}

#include "PageDTO.tpp"

#endif //FUNIXPRODUCTIONSCORE_PAGEDTO_H
