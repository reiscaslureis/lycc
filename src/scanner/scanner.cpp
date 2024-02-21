#include "scanner/scanner.hpp"

Scanner::Scanner(std::string source) {
    if (source.find(".lyc") != std::string::npos) {
        this -> source = std::make_shared<std::ifstream>(std::move(source)); } 
    
    else { this -> source = std::make_shared<std::istringstream>(std::move(source)); }

    this -> tokens = std::make_shared<std::map<std::string, std::string>>();

    this -> tokens -> insert({
        {"=", "ASSIGNMENT"},
        {"==", "EQUAL"},
        {"!=", "NOT_EQUAL"},
        {">", "GREATER_THAN"},
        {"<", "LESS_THAN"},
        {">=", "GREATER_THAN_OR_EQUAL"},
        {"<=", "LESS_THAN_OR_EQUAL"},
        {"{", "OPEN_BRACE"},
        {"}", "CLOSE_BRACE"},
        {"(", "OPEN_PARENTHESES"},
        {")", "CLOSE_PARENTHESES"},
        {"+", "ADDITION"},
        {"++", "INCREMENT"},
        {"-", "SUBTRACTION"},
        {"--", "DECREMENT"},
        {"/", "DIVISION"},
        {"%", "MODULO"},
        {"^", "EXPONENTATION"},
        {"*", "MULTIPLICATION"},
        {";", "SEMICOLON"},
        {",", "COLON"},
        {"and", "AND"},
        {"or", "OR"},
        {"true", "TRUE"},
        {"false", "FALSE"},
        {"while", "WHILE"},
        {"if", "IF"},
        {"else if", "ELSE_IF"},
        {"else", "ELSE"}
    });
}

bool Scanner::isSymbol(char c) {
    std::string symbols = "=!><{}[]-+%^*;";
    return symbols.find_first_of(c) != std::string::npos;
}

std::string Scanner::getSymbol() {
    char temp = this -> source -> get();
    std::string lexeme = ""; lexeme += temp;

    switch (temp) {
        case '=': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); }
        case '!': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); }
        case '<': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); }
        case '>': if (this -> source -> peek() == '=') { lexeme += this -> source -> get(); }
        case '+': if (this -> source -> peek() == '+') { lexeme += this -> source -> get(); }
        case '-': if (this -> source -> peek() == '-') { lexeme += this -> source -> get(); }

        default: break;

    } return lexeme;
}

bool Scanner::isAlphaNumeric(char c) { return (isalpha(c) || c == '_') ? true : false; }

std::string Scanner::getAlphaNumeric() { 
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

bool Scanner::isEOF() { return this -> source -> peek() == EOF; }

std::shared_ptr<Token> Scanner::nextToken(bool traceScanner) {
    auto trace = [this]() {
        std::shared_ptr<Token> token = this -> nextToken(false);

        std::cout << token -> getLexeme() << ' ' << token -> getType() << '\n';
        return token;
    };

    if (traceScanner == true) { return trace(); }

    while (std::isspace(this -> source -> peek())) { this -> source -> get(); }
       
    if (isAlphaNumeric(this -> source -> peek())) {
        std::string alphaNumeric = this -> getAlphaNumeric();

        auto it = this -> tokens -> find(alphaNumeric);
        if (it != this -> tokens -> end()) { return std::make_shared<Token>(alphaNumeric, it -> second); }

        return std::make_shared<Token>(alphaNumeric, "IDENTIFIER");
    }
    
    if (isdigit(this -> source -> peek())) {
        return std::make_shared<Token>(this -> getIntegerLiteral(), "INTEGER_LITERAL");
    }

    if (isSymbol(this -> source -> peek())) {
        std::string symbol = this -> getSymbol();
        
        auto it = this -> tokens -> find(symbol);
        if (it != this -> tokens -> end()) { return std::make_shared<Token>(symbol, it -> second); }

        return std::make_shared<Token>(symbol, "UNKNOWN");
    }

    return std::make_shared<Token>(std::string(1, this -> source -> get()), "UNKNOWN");
}