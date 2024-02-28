#include "scanner/scanner.hpp"

Scanner::Scanner(std::string source) {
    if (source.find(".lyc") != std::string::npos) {
        this -> source = std::make_shared<std::ifstream>(std::move(source)); } 
    
    else { this -> source = std::make_shared<std::istringstream>(std::move(source)); }

    this -> tags.insert({
        {"=", "ASSIGN"}, {"'", "SQUOTE"}, {"==", "EQUAL"}, {"!=", "NEQUAL"}, {">", "GTHAN"},
        {"<", "LTHAN"}, {">=", "GTEQUAL"}, {"<=", "LTEQUAL"}, {"(", "OPAREN"}, {")", "CPAREN"},
        {"/", "DIV"}, {"%", "MOD"}, {"^", "EXPO"}, {"*", "MUL"}, {"-", "SUB"}, {"+", "ADD"},
        {"++", "INC"}, {"--", "DEC"}, {";", "SEMI"}, {"output", "OUTPUT"}, {"and", "AND"},
        {"or", "OR"}, {"true", "TRUE"}, {"false", "FALSE"},
    });
}

bool Scanner::isSymbol(char c) {
    std::string symbols = "=!><()-+%^*;'";
    return symbols.find_first_of(c) != std::string::npos;
}

std::string Scanner::getSymbol() {
    char temp = this -> source -> get(); std::string lexeme = ""; lexeme += temp;

    if (temp == '\'') { this -> inString = !(this -> inString); }

    switch (temp) {
        case '=': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); } break;
        case '!': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); } break;
        case '<': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); } break;
        case '>': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); } break;
        case '+': if (this -> source -> peek() == '+') { lexeme += this -> source -> get(); } break;
        case '-': if (this -> source -> peek() == '-') { lexeme += this -> source -> get(); } break;

        default: break;

    } return lexeme;
}

std::string Scanner::getIdentifier() { 
    std::string lexeme = "";

    while (isalpha(this -> source -> peek()) || this -> source -> peek() == '_') {
        lexeme += this -> source -> get();

    } return lexeme;
}

std::string Scanner::getIntegerLiteral() {
    std::string lexeme = "";

    while (isalnum(this -> source -> peek())) {
        lexeme += this -> source -> get();

    } return lexeme;
}

std::string Scanner::getStringLiteral() {
    std::string lexeme = "";

    while (this -> source -> peek() != '\'') { lexeme += this -> source -> get(); }
    return lexeme;
}

bool Scanner::isEOF() { return this -> source -> peek() == EOF; }

std::shared_ptr<Token> Scanner::nextToken(bool traceScanner) {
    auto trace = [this]() {
        std::shared_ptr<Token> token = this -> nextToken(false);

        std::cout << std::setw(7) << std::right << token -> getType() << ' ';
        std::cout << std::left << token -> getLexeme() << std::endl;

        return token;
    }; if (traceScanner == true) { return trace(); }

    while (std::isspace(this -> source -> peek()) && this -> inString == false) { this -> source -> get(); }

    if (this -> isSymbol(this -> source -> peek())) {
        std::string symbol = this -> getSymbol();

        auto it = this -> tags.find(symbol);
        if (it != this -> tags.end()) { return std::make_shared<Token>(symbol, it -> second); }

        return std::make_shared<Token>(symbol, "UNKNOWN");
    }

    if (this -> inString == true) { return std::make_shared<Token>(this -> getStringLiteral(), "STRLIT"); }
       
    if (isalpha(this -> source -> peek()) || this -> source -> peek() == '_') {
        std::string identifier = this -> getIdentifier();

        auto it = this -> tags.find(identifier);
        if (it != this -> tags.end()) { return std::make_shared<Token>(identifier, it -> second); }

        return std::make_shared<Token>(identifier, "ID");
    }
    
    if (isdigit(this -> source -> peek())) {
        return std::make_shared<Token>(this -> getIntegerLiteral(), "INTLIT");
    }

    return std::make_shared<Token>(std::string(1, this -> source -> get()), "UNKNOWN");
}