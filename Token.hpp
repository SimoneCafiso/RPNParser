//
// Created by cafis on 12/15/2024.
//

#ifndef RPNPARSER_TOKEN_HPP
#define RPNPARSER_TOKEN_HPP

#include <iostream>
#include <string>

namespace ctk {

    enum class TokenType {
        NUMBER,
        OPERATOR,
        BRACKET,
        UNKNOWN
    };

    class Token {
    public:
        Token(TokenType type, const std::string &value);

        [[nodiscard]] TokenType getType() const { return type; };
        [[nodiscard]] const std::string& getValue() const { return value; }

        void printDebug() const {
            std::cout << "Token(Type: " << static_cast<int>(type)
                      << ", Value: " << value << ")" << std::endl;
        }

    private:
        TokenType type;
        std::string value;

    };

} // ctk

#endif //RPNPARSER_TOKEN_HPP
