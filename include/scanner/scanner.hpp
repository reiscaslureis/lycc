#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <memory>

#include "token.hpp"
#include "tag.hpp"

class Scanner {
    private:
        std::unique_ptr<std::istream> source;
        char peek;

    	bool skipChar(char c);
        void nextChar();
        std::string getIntegerLiteral();

    public:
        Scanner(std::string source);
        
        Token nextToken();
        bool isEOF();
};