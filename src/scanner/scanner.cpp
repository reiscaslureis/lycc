#include "scanner/scanner.hpp"

Scanner::Scanner(std::string source) : source(source) {
    this -> nextChar();
}

bool Scanner::skipChar(char c) {
    switch (c) {
        case ' ': case '\t': case '\r':
            return true;
            break;
        
        default: return false;
    }
}

void Scanner::nextChar() {   
    do { this -> source.get(this -> peek);
    } while (this -> skipChar(this -> peek));
}

bool Scanner::isEOF() { return (this -> source.eof()) ? true : false; }

std::string Scanner::getIntegerLiteral() {
    std::string integer_literal = "";

    while (std::isdigit(this -> peek) && !this -> isEOF()) { 
        integer_literal += this -> peek; 
        this -> nextChar();    
    }

    return integer_literal;
}

Token Scanner::nextToken() {
    switch (this -> peek) {

        case '+':
            this -> nextChar();
            return Token(Tag::ADDITION, "+");

        case '-':
            this -> nextChar();
            return Token(Tag::SUBTRACTION, "-");

        case '*':
            this -> nextChar();
            return Token(Tag::MULTIPLICATION, "*");

        case '/':
            this -> nextChar();
            return Token(Tag::DIVISION, "/");

        case '^':
            this -> nextChar();
            return Token(Tag::EXPONENTIATION, "^");

        case '%':
            this -> nextChar();
            return Token(Tag::MODULO, "%");

        case '(':
            this -> nextChar();
            return Token(Tag::OPEN_PARENTHESES, "(");

        case ')':
            this -> nextChar();
            return Token(Tag::CLOSE_PARENTHESES, ")");
        
        default:
            if (std::isdigit(this -> peek)) {
                return Token(Tag::INTEGER_LITERAL, this -> getIntegerLiteral());
            }
            
            this -> nextChar();
            return Token(Tag::UNKNOWN, "UNKNOWN");
    }
}