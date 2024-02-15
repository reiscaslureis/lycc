#include "scanner/scanner.hpp"

#include <iostream>

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

Token Scanner::nextToken(bool print) {
    auto traceNextToken = [this]() {
        Token token = this -> nextToken();
        
        std::cout << token.getLexeme() << ' ';
        std::cout << enumTagToString(token.getTag()) << '\n';

        return token;
    };

    if (print) { return traceNextToken(); }

    char temp = this -> peek;

    switch (this -> peek) {
        case '+': case '-': case '*': case '/': case '^': case '%': case '(':
        case ')': case '\n':
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
            case '\n': return Token(Tag::NEWLINE, "\\n");    
        }

        default:
            if (std::isdigit(this -> peek)) {
                return Token(Tag::INTEGER_LITERAL, this -> getIntegerLiteral());
            }
            
            this -> nextChar();
            return Token(Tag::UNKNOWN, std::string(1, temp));
    }
}