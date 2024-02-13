#include "main.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) { return EXIT_FAILURE; }
    
    std::unique_ptr<Scanner> scanner = std::make_unique<Scanner>(std::string(argv[1]));

    while (!scanner -> isEOF())  {
        Token token = scanner -> nextToken();
        
        std::cout << token.getLexeme() << ' ';
        std::cout << enumTagToString(token.getTag()) << '\n';
    }

    return EXIT_SUCCESS;
}