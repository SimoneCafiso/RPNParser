cmake_minimum_required(VERSION 3.22)
project(RPNParser)

set(CMAKE_CXX_STANDARD 23)

add_executable(RPNParser main.cpp
        Token.cpp
        Token.hpp
        Tokenizer.cpp
        Tokenizer.hpp
        RPNParser.cpp
        RPNParser.hpp)
