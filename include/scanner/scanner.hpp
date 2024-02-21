#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <iostream>

#include "token.hpp"

class Scanner {
    private:
        std::shared_ptr<std::istream> source;
        std::shared_ptr<std::map<std::string, std::string>> tokens;

        bool isSymbol(char symbol);
        bool isAlphaNumeric(char c);

        std::string getAlphaNumeric();
        std::string getIntegerLiteral();
        std::string getSymbol();

    public:
        Scanner(std::string source);

        std::shared_ptr<Token> nextToken(bool traceScanner = false);
        bool isEOF();
};