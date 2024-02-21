#pragma once

#include <string>

class Token {
    private:
        std::string lexeme;
        std::string type;
        
    public:
        Token(std::string lexeme, std::string type);

        std::string getLexeme();
        std::string getType();
};
