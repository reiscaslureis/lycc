#pragma once

#include <fstream>
#include <string>
#include <map>

#include "token.hpp"
#include "tag.hpp"

class Scanner {
    private:
        std::ifstream source;
        char peek;

    	bool skipChar(char c);
        void nextChar();
        std::string getIntegerLiteral();

    public:
        Scanner(std::string source);
        
        Token nextToken();
        bool isEOF();
};