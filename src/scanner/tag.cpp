#include "scanner/tag.hpp"

std::string enumTagToString(Tag tag) {

    switch(tag) {
        
        case Tag::ADDITION: return "ADDITION";
        case Tag::SUBTRACTION: return "SUBTRACTION";
        case Tag::MULTIPLICATION: return "MULTIPLICATION";
        case Tag::DIVISION: return "DIVISION";
        case Tag::EXPONENTIATION: return "EXPONENTIATION";
        case Tag::MODULO: return "MODULO";
        case Tag::INTEGER_LITERAL: return "INTEGER_LITERAL";
        case Tag::OPEN_PARENTHESES: return "OPEN_PARENTHESES";
        case Tag::CLOSE_PARENTHESES: return "CLOSE_PARENTHESES";
        case Tag::UNKNOWN: return "UNKNOWN";
        
        default: return "unknown tag";
    }
}