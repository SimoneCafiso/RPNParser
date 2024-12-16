//
// Created by cafis on 12/15/2024.
//

#ifndef RPNPARSER_RPNPARSER_HPP
#define RPNPARSER_RPNPARSER_HPP

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>
#include <bits/stdc++.h>
#include "Tokenizer.hpp"

namespace cps {

    class RPNParser {
    public:
        explicit RPNParser(std::string &rpnExpression);

        double evaluate();

    private:
        std::stack<ctk::Token> tokens;
        std::string rpnExpression;
        std::unordered_map<char, std::function<double(double, double)>> operators = {
                {
                        '+', [](double first, double second) { return first + second; },
                },
                {
                        '-', [](double first, double second) { return first - second; },
                },
                {
                        '*', [](double first, double second) { return first * second; },
                },
                {
                        '/', [](double first, double second) {
                                 if (second == 0) {
                                     throw std::runtime_error("Divisione per 0 !");
                                 }
                                 return first / second;
                            },
                },
                {
                        '^', [](double base, double power) { return std::pow(base, power); },
                },
        };

        static bool isRpnValid() { return true; };
    };

} // cps

#endif //RPNPARSER_RPNPARSER_HPP
