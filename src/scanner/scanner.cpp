#include "scanner/scanner.hpp"

Scanner::Scanner(std::string source) {
    if (source.find(".lyc") != std::string::npos) {
        this -> source = std::make_shared<std::ifstream>(std::move(source)); } 
    
    else { this -> source = std::make_shared<std::istringstream>(std::move(source)); }
}

void Scanner::updateIndentValue() {
    int temp = 0, aux = this -> indentLevel;
    while (this -> source -> peek() == '\t') {
        ++temp;
        this -> source -> get();
    } 

    this -> indentLevel += temp - this -> indentLevel;
    this -> nextIndent = this -> indentLevel - aux;
    this -> checkIndent = false;
}

std::shared_ptr<Token> Scanner::getNewline() {
    while (this -> source -> peek() == '\n') { this -> source -> get(); }
    this -> checkIndent = true;
        
    return std::make_shared<Token>("newline", "NEWLINE");
}

bool Scanner::isEOF() { return this -> source -> peek() == EOF; }

std::shared_ptr<Token> Scanner::nextToken() {
    if (this -> source -> peek() == '\n') { return this -> getNewline(); }
    if (this -> checkIndent == true) { this -> updateIndentValue(); }

    if (this -> nextIndent > 0) {
        --(this -> nextIndent);
        return std::make_shared<Token>("indent", "INDENT");

    } else if (this -> nextIndent < 0) {
        ++(this -> nextIndent);
        return std::make_shared<Token>("dedent", "DEDENT");
    }

    return std::make_shared<Token>(std::string(1, this -> source -> get()), "UNKNOWN");
}