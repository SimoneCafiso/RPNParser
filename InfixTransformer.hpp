//
// Created by cafis on 12/16/2024.
//

#ifndef RPNPARSER_INFIXTRANSFORMER_HPP
#define RPNPARSER_INFIXTRANSFORMER_HPP

#include <iostream>
#include <string>
#include <stack>
#include "Tokenizer.hpp"

class InfixTransformer {

public:
    InfixTransformer(const std::string &infixExpression);

    std::string producePostfix();

private:
    std::string infixExpression;

    std::string postfixExpression = "";
    std::stack<char> operators;

    void handleOperators(ctk::Token &current);
    void handleBrackets(ctk::Token &current);

    int getOperatorHierarchy(char op) const;

    bool isBracket(char c) {
        return c == '(' || c == ')';
    }
};


#endif //RPNPARSER_INFIXTRANSFORMER_HPP
