#include "scanner/scanner.hpp"

Scanner::Scanner(std::string source) {
    if (source.find(".lyc") != std::string::npos) {
        this -> source = std::make_unique<std::ifstream>(std::move(source));

    } else { this -> source = std::make_unique<std::istringstream>(std::move(source)); }

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
    do { this -> source -> get(this -> peek);
    } while (this -> skipChar(this -> peek));
}

bool Scanner::isEOF() { return (this -> source -> eof()) ? true : false; }

std::string Scanner::getIntegerLiteral() {
    std::string integer_literal = "";

    while (std::isdigit(this -> peek) && !this -> isEOF()) { 
        integer_literal += this -> peek; 
        this -> nextChar();    
    }

    return integer_literal;
}

Token Scanner::nextToken() {
    char temp = this -> peek;

    switch (this -> peek) {
        case '+': case '-': case '*': case '/': case '^': case '%': case '(': case ')':
            this -> nextChar();

        switch (temp) {
            case '+': return Token(Tag::ADDITION, "+");
            case '-': return Token(Tag::SUBTRACTION, "-");
            case '*': return Token(Tag::MULTIPLICATION, "*");
            case '/': return Token(Tag::DIVISION, "/");
            case '^': return Token(Tag::EXPONENTIATION, "^");
            case '%': return Token(Tag::MODULO, "%");
            case '(': return Token(Tag::OPEN_PARENTHESES, "(");
            case ')': return Token(Tag::CLOSE_PARENTHESES, ")");     
        }

        default:
            if (std::isdigit(this -> peek)) {
                return Token(Tag::INTEGER_LITERAL, this -> getIntegerLiteral());
            }
            
            this -> nextChar();
            return Token(Tag::UNKNOWN, "UNKNOWN");
    }
}