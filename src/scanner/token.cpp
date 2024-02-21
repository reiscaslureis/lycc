#include "scanner/token.hpp"

Token::Token(std::string lexeme, std::string type) : lexeme(lexeme), type(type) {}

std::string Token::getLexeme() { return this -> lexeme; }
std::string Token::getType() { return this -> type; }