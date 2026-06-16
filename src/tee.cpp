#include "lib.hpp"
#include <iostream>
#include <fstream>

/*
 * The `tee` command reads stdin and writes to both stdout and a file.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "tee: missing file argument" << std::endl;
        return 2;
    }

    std::ofstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "tee: failed to open " << argv[1] << std::endl;
        return 1;
    }

    loop {
        std::string stdin;
        std::cin >> stdin;

        std::cout << stdin;

        try {
            file << stdin;
        } catch (const std::filesystem::__cxx11::filesystem_error& e) {
            std::cerr << "tee: failed to write to " << argv[1] << std::endl;
            return 1;
        }
    }
}
