#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <memory>
#include <vector>

#include "token.hpp"
#include "tag.hpp"

class Scanner {
    private:
        std::unique_ptr<std::istream> source;
        std::map <std::string, Tag> keywords;
        char peek;

    	bool skipChar(char c);
        void nextChar(bool skipChar = true);

    public:
        Scanner(std::string source);
        
        Token nextToken(bool print = false);
        bool isEOF();
};