#include <iostream>
#include <filesystem>

/*
 * The `mv` program moves/renames files.
 */

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "mv: not enough arguments" << std::endl;
        return 2;
    }

    try {
        std::filesystem::rename(argv[1], argv[2]);
    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "An error occured: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
