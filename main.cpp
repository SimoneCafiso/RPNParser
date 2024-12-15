//
// Created by cafis on 12/15/2024.
//


#include <iostream>
#include "string"
#include "RPNParser.hpp"

int main() {

    std::cout << "Inserisci un espressione valida nella notazione polacca inversa ==> " << std::endl;
    std::string in;
    std::getline(std::cin, in);
    cps::RPNParser parser(in);
    std::cout << parser.evaluate() << std::endl;

    return 0;
}