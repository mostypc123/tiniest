#include <iostream>

/*
 * The `seq` command prints a sequence of numbers.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "seq: missing range" << std::endl;
        return 2;
    }

    if (argc == 2) {
        std::cout << "seq: missing end" << std::endl;
        return 2;
    }

    int begin = 1;
    int step = 1;
    int end = 1; // this is to supress warnings, it gets changed

    try {
        begin = std::stoi(argv[1]);

        if (argc == 4) {
            step = std::stoi(argv[2]);
            end = std::stoi(argv[3]);
        }

        if (argc == 3) {
            end = std::stoi(argv[2]);
        }
    } catch (const std::exception&) {
        std::cout << "seq: invalid number" << std::endl;
        return 2;
    }

    for (int i = begin; i <= end; i+=step) {
        std::cout << i << std::endl;
    }

    return 0;
}
