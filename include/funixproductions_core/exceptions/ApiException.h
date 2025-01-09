//
// Created by Antoine Pronnier on 07/01/2025.
//

#ifndef FUNIXPRODUCTIONSCORE_APIEXCEPTION_H
#define FUNIXPRODUCTIONSCORE_APIEXCEPTION_H

#include <exception>
#include <optional>
#include <string>

namespace funixproductions_core {
    class ApiException: public std::exception {
    public:
        explicit ApiException(const std::string &message);
        ApiException(const std::string &message, const std::exception &cause);
        ApiException(const std::string &message, const std::string &httpBodyResponse);
        ApiException(const std::string &message, const std::string &httpBodyResponse, const std::exception &cause);

        [[nodiscard]] const char *what() const noexcept override;

        [[nodiscard]] virtual const std::optional<std::string> &getServerHttpMessage() const final;
    private:
        std::string message;
        std::optional<std::string> serverHttpMessage;

        void setServerHttpMessage(const std::string &httpBodyResponse);
    };
}

#endif //FUNIXPRODUCTIONSCORE_APIEXCEPTION_H
