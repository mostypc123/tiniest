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

    std::string input;
    while (std::cin >> input) {
        std::cout << input;

        file << input;
    }
}
