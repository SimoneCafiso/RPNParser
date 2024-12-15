//
// Created by cafis on 12/15/2024.
//

#include "Tokenizer.hpp"

namespace ctk {

    Tokenizer::Tokenizer(const std::string &input) : input(input), position(0) {
        // implementare
    }


    Token Tokenizer::extractNum() {
        size_t start = position;
        bool isDecimal = false;
        while (position < this->input.size() && (std::isdigit(this->input[position]) || this->input[position] == '.')) {
            if (this->input[position] == '.') {
                if (isDecimal)
                    throw std::runtime_error("Errore, numero non valido, due punti decimali");
                isDecimal = true;
            }
            position++;
        }

        return Token(TokenType::NUMBER, input.substr(start, position - start));

    }


    Token Tokenizer::nextToken() {
        if (position >= input.size()) {
            return Token(TokenType::UNKNOWN, nullptr);
        }

        while (position < this->input.size() && std::isspace(this->input[position])) {
            position++;
        }

        char c = this->input[position];
        if (isDigit(c)) {
            return extractNum();
        } else if (isOperator(c)) {
            //prima legge la posizione poi incrementa position;
            return Token(TokenType::OPERATOR, std::string(1, input[position++]));
        }

        return Token(TokenType::UNKNOWN, std::string(1, input[position++]));
    }

        bool Tokenizer::hasMoreTokens() {
            return this->position < this->input.size();
        }
    } // ctk