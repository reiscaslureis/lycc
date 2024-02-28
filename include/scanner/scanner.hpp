#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>

#include "token.hpp"

class Scanner {
    private:
        std::shared_ptr<std::istream> source;
        std::map<std::string, std::string> tags;

        bool inString = false;

        bool isSymbol(char symbol);

        std::string getIdentifier();
        std::string getIntegerLiteral();
        std::string getStringLiteral();
        std::string getSymbol();

    public:
        Scanner(std::string source);

        std::shared_ptr<Token> nextToken(bool traceScanner = false);
        bool isEOF();
};