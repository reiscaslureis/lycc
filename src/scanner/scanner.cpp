#include "scanner/scanner.hpp"

#include <iostream>

Scanner::Scanner(std::string source) {
    if (source.find(".lyc") != std::string::npos) {
        this -> source = std::make_unique<std::ifstream>(std::move(source));

    } else { this -> source = std::make_unique<std::istringstream>(std::move(source)); }

    this -> keywords["and"] = Tag::AND;
    this -> keywords["or"] = Tag::OR;
    this -> keywords["true"] = Tag::TRUE;
    this -> keywords["false"] = Tag::FALSE;

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

void Scanner::nextChar(bool skipChar) {   
    if (skipChar == true) {
        do { this -> source -> get(this -> peek); } 
        while (this -> skipChar(this -> peek) && !this -> isEOF());
    
    } else { this -> source -> get(this -> peek); }
}

bool Scanner::isEOF() { return (this -> source -> eof()) ? true : false; }

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
        case ')': case '\n': case '<': case '>': case '=': case '!':
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
            case '\n': return Token(Tag::ENDLINE, "\\n");

            case '<': 
                if (this -> peek == '=') { 
                    this -> nextChar();
                    return Token(Tag::LESS_THAN_OR_EQUAL, "<="); }

                else { return Token(Tag::LESS_THAN, "<"); }
            
            case '>': 
                if (this -> peek == '=') { 
                    this -> nextChar();
                    return Token(Tag::GREATER_THAN_OR_EQUAL , ">="); }

                else { return Token(Tag::GREATER_THAN   , ">"); }

            case '!':
                if (this -> peek == '=') { 
                    this -> nextChar();
                    return Token(Tag::NOT_EQUAL , "!="); }

                else { return Token(Tag::NOT , "!"); }      

            case '=':
                if (this -> peek == '=' && !this -> isEOF()) { 
                    std::cout << "outr giau\n";
                    this -> nextChar();
                    return Token(Tag::EQUAL , "=="); }

                else { return Token(Tag::ASSIGNMENT , "="); }        
        }

        default:
            if (std::isdigit(this -> peek)) {
                std::string digitTemp = "";

                do {
                    digitTemp += this -> peek;
                    this -> nextChar(false);    

                } while (std::isdigit(this -> peek) && !this -> isEOF() && this -> peek != ' ');

                if (this -> peek == ' ') { this -> nextChar(); }
                
                return Token(Tag::INTEGER_LITERAL, digitTemp);

            } else if (std::isalpha(this -> peek) or this -> peek == '_') {
                std::string alphaTemp = "";

                do {
                    alphaTemp += this -> peek; 
                    this -> nextChar(false);

                } while ((std::isalnum(this -> peek) or this -> peek == '_') 
                                                     && !this -> isEOF() && this -> peek != ' ');

                if (this -> peek == ' ') { this -> nextChar(); }
                
                auto it = this -> keywords.find(alphaTemp);
                if (it != this -> keywords.end()) { return Token(it -> second, alphaTemp); };

                return Token(Tag::UNKNOWN, alphaTemp);
            }
               
            this -> nextChar();
            return Token(Tag::UNKNOWN, std::string(1, temp));
    }
}