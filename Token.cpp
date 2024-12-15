//
// Created by cafis on 12/15/2024.
//

#include "Token.hpp"

#include <utility>

namespace ctk {
    Token::Token(TokenType type, const std::string& value) : type (type), value(value){

    }
} // ctk