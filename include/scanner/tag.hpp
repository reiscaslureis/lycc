#pragma once

#include <string>

enum class Tag {
    ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, EXPONENTIATION, MODULO,
    INTEGER_LITERAL,
    OPEN_PARENTHESES, CLOSE_PARENTHESES, NEWLINE,
    UNKNOWN
};

std::string enumTagToString(Tag tag);   