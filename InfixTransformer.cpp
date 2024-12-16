//
// Created by cafis on 12/16/2024.
//

#include "InfixTransformer.hpp"

InfixTransformer::InfixTransformer(const std::string &infixExpression) : infixExpression(infixExpression) {

}

int InfixTransformer::getOperatorHierarchy(char op) const{

    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }

    throw std::runtime_error("Operatore non riconosciuto!");
}


void InfixTransformer::handleOperators(ctk::Token &current) {
    char currentChar = current.getValue()[0];
    if (!this->operators.empty() && !isBracket(this->operators.top())) {
        while (!this->operators.empty() && getOperatorHierarchy(currentChar) <= getOperatorHierarchy(this->operators.top())) {
            postfixExpression += this->operators.top();
            this->operators.pop();
        }
    }

    this->operators.push(currentChar);

}


void InfixTransformer::handleBrackets(ctk::Token &current) {
    char currentChar = current.getValue()[0];

    if (currentChar == '(') {
        this->operators.push(currentChar);
    } else if (current.getValue()[0] == ')') {


        while (this->operators.top() != '(') {
            postfixExpression += this->operators.top();
            this->operators.pop();
        }

        //rimuoviamo l'apertura della parentesi
        this->operators.pop();
    }
}

std::string InfixTransformer::producePostfix() {
    ctk::Tokenizer tokenizer(this->infixExpression);

    while (tokenizer.hasMoreTokens()) {
        ctk::Token current = tokenizer.nextToken();

        if (current.getType() == ctk::TokenType::NUMBER) {
            postfixExpression += (current.getValue() + " "); // Aggiungiamo lo spazio durante la concatenazione di due numeri in modo tale da renderli separati, senno' sembrerebbero cifre dello stesso numero!!
        } else if (current.getType() == ctk::TokenType::OPERATOR) {
            handleOperators(current);

        } else if (current.getType() == ctk::TokenType::BRACKET) {
            handleBrackets(current);
        }
    }

    while (!this->operators.empty()) {
        postfixExpression += this->operators.top();
        this->operators.pop();
    }

    return postfixExpression;


}




