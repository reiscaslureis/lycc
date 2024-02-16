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
        case Tag::NEWLINE: return "NEWLINE";
        case Tag::GREATER_THAN: return "GREATER_THAN";
        case Tag::LESS_THAN: return "LESS_THAN";
        case Tag::GREATER_THAN_OR_EQUAL: return "GREATER_THAN_OR_EQUAL";
        case Tag::LESS_THAN_OR_EQUAL: return "LESS_THAN_OR_EQUAL";
        case Tag::EQUAL: return "EQUAL";
        case Tag::NOT_EQUAL: return "NOT_EQUAL";
        case Tag::BOOLEAN_LITERAL: return "BOOLEAN_LITERAL";
        case Tag::AND: return "AND";
        case Tag::OR: return "OR";
        case Tag::TRUE: return "TRUE";
        case Tag::FALSE: return "FALSE";
        case Tag::NOT: return "NOT";
        case Tag::ASSIGNMENT: return "ASSIGNMENT";
        case Tag::COMMA: return "COMMA";
        case Tag::IDENTIFIER: return "IDENTIFIER";
        
        default: return "unknown tag";
    }
}