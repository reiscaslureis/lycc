#include "scanner/token.hpp"

Token::Token(Tag tag, std::string lexeme) : tag(tag), lexeme(lexeme) {  }

Tag Token::getTag() { return this -> tag; }

std::string Token::getLexeme() { return this -> lexeme; }