#include "main.hpp"

int main(int argc, char *argv[]) {
    std::unique_ptr<Scanner> scanner = std::make_unique<Scanner>(argv[1]);

    while (!scanner -> isEOF())  {
        Token token = scanner -> nextToken();
        
        std::cout << token.getLexeme() << ' ';
        std::cout << enumTagToString(token.getTag()) << '\n';
    }
    
    return EXIT_SUCCESS;
}