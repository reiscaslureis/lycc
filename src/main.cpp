#include "main.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) { return EXIT_FAILURE; }

    bool traceScanner = false;

    for (size_t i = 2; i < argc; ++i)  {
        std::string arg = argv[i];

        if (arg == "--scanner" || arg == "-s") { traceScanner = true; }
    }
    
    std::shared_ptr<Scanner> scanner = std::make_shared<Scanner>(argv[1]);
    std::shared_ptr<Token> token;

    while (!scanner -> isEOF()) { token = scanner -> nextToken(traceScanner); }

    return EXIT_SUCCESS;
}