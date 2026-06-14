#include <fstream>
#include <iostream>

/*
 * The `touch` command creates a new file.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "touch: you must specify the file to create." << std::endl;
        return 2;
    }
    std::string file_arg = argv[1];

    std::ofstream file(file_arg);
    file << "";
    return 0;
}
