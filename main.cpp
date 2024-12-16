//
// Created by cafis on 12/15/2024.
//


#include <iostream>
#include "string"
#include "RPNParser.hpp"
#include "InfixTransformer.hpp"

int main() {
    std::cout << "Inserisci un espressione valida nella notazione standard ==> " << std::endl;
    std::string in;
    std::getline(std::cin, in);
    InfixTransformer transformer(in);
    in =  transformer.producePostfix();
    std::cout << in <<  " -> POSTFIX" << std::endl;
    cps::RPNParser parser(in);
    std::cout << parser.evaluate() << std::endl;

    return 0;
}
