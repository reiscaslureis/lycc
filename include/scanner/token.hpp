#pragma once

#include <string>

#include "tag.hpp"

class Token {
    private:
        std::string lexeme;
        Tag tag;
        
    public:
        Token(Tag tag, std::string lexeme);

        Tag getTag();
        std::string getLexeme();
};
