//
// Created by cafis on 12/15/2024.
//

#include "RPNParser.hpp"

namespace cps {
    RPNParser::RPNParser(std::string &rpnExpression) : rpnExpression(rpnExpression) {

    }

    double RPNParser::evaluate() {
        ctk::Tokenizer tokenizer(this->rpnExpression);
        while (tokenizer.hasMoreTokens()) {
            ctk::Token token = tokenizer.nextToken();
            //token.printDebug();
            if (token.getType() == ctk::TokenType::NUMBER) {
                this->tokens.push(token);
            } else if (token.getType() == ctk::TokenType::OPERATOR) {
                ctk::Token secondToken = this->tokens.top();
                this->tokens.pop();
                ctk::Token firstToken = this->tokens.top();
                this->tokens.pop();

                if (token.getValue() == "+") {
                    this->tokens.push(ctk::Token(ctk::TokenType::NUMBER, std::to_string(std::stod(firstToken.getValue()) + std::stod(secondToken.getValue()))));
                } else if (token.getValue() == "-") {
                    this->tokens.push(ctk::Token(ctk::TokenType::NUMBER, std::to_string(std::stod(firstToken.getValue()) - std::stod(secondToken.getValue()))));
                } else if (token.getValue() == "*") {
                    this->tokens.push(ctk::Token(ctk::TokenType::NUMBER, std::to_string(std::stod(firstToken.getValue()) * std::stod(secondToken.getValue()))));
                } else if (token.getValue() == "/") {
                    if (std::stod(secondToken.getValue()) == 0.0) {
                        throw std::runtime_error("Errore: Divisione per 0!");
                    }
                    this->tokens.push(ctk::Token(ctk::TokenType::NUMBER, std::to_string(std::stod(firstToken.getValue()) / std::stod(secondToken.getValue()))));
                } else {
                    throw std::runtime_error("Operatore non supportato: " + token.getValue());

                }
            }
        }
        return std::stod(this->tokens.top().getValue());
    }


} // cps