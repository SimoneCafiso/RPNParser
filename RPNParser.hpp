//
// Created by cafis on 12/15/2024.
//

#ifndef RPNPARSER_RPNPARSER_HPP
#define RPNPARSER_RPNPARSER_HPP

#include <iostream>
#include <string>
#include <stack>
#include "Tokenizer.hpp"

namespace cps {

    class RPNParser {
        public:
            explicit RPNParser (std::string & rpnExpression);
            double evaluate();
        private:
            std::stack<ctk::Token> tokens;
            std::string rpnExpression;
            static bool isRpnValid() { return true; };
    };

} // cps

#endif //RPNPARSER_RPNPARSER_HPP
