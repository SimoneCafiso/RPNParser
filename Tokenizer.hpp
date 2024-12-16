//
// Created by cafis on 12/15/2024.
//

#ifndef RPNPARSER_TOKENIZER_HPP
#define RPNPARSER_TOKENIZER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Token.hpp"

namespace ctk {

    class Tokenizer {
    public:
        explicit Tokenizer(const std::string& input);
        Token nextToken();
        bool hasMoreTokens();
    private:
        std::string input;
        size_t position;

        [[nodiscard]] static bool isDigit(char ch) { return std::isdigit(ch); }
        [[nodiscard]] static bool isOperator(char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'; }
        [[nodiscard]] static bool isBracket(char ch) { return ch == '(' || ch == ')'; }

        Token extractNum();
    };

} // ctk

#endif //RPNPARSER_TOKENIZER_HPP
