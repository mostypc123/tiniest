#include <iostream>
#include <cstdio>
#include <filesystem>

/*
 * The `rmdir` command deletes empty directories.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "rmdir: no specified dir to delete" << std::endl;
        return 2;
    }

    if (!std::filesystem::is_empty(argv[1])) {
        std::cout << "rmdir: " << argv[1] << " is not empty" << std::endl;
        std::cout << "maybe try to use the rm command with the -r flag?" << std::endl;
        return 2;
    }

    std::remove(argv[1]);
    if (std::filesystem::exists(argv[1])) {
        std::cout << "rmdir: failed to delete " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
