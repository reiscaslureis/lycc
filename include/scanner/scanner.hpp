#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <regex>
#include <iostream>

#include "token.hpp"

class Scanner {
    private:
        std::shared_ptr<std::istream> source;
        
        //std::regex keywords;

        int indentLevel = 0, nextIndent;
        int checkIndent = false;

        std::shared_ptr<Token> getNewline();

        void updateIndentValue();

        //std::regex regexIL;
        //std::regex regexID;

        //void nextChar();

    public:
        Scanner(std::string source);

        std::shared_ptr<Token> nextToken();
        bool isEOF();
};