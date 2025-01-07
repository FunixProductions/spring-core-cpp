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

            const bool hasNext() const;
            const bool hasPrevious() const;

            const long getTotalElementsDatabase() const;
            const int getTotalPages() const;
            const int getActualPage() const;
            const int getTotalElementsThisPage() const;

        private:
            std::list<T> content;
            int totalPages;
            int actualPage;
            long totalElementsDatabase;
            int totalElementsThisPage;
    };

}

#endif //FUNIXPRODUCTIONSCORE_PAGEDTO_H
