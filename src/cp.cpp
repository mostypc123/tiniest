#include <filesystem>
#include <iostream>
#include <cstring>

/*
 * The `cp` command copies files. Use -r to copy directories (-r stands for recusion).
 * The --safe flag refuses to copy files when the destination already exists.
 */

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "cp: not enough arguments" << std::endl;
        return 2;
    }

    bool recursive = false;
    bool safe = false;
    if (argc > 3) {
        for (int i = 3; i < argc; i++) {
            if (argv[i]) {
                if (!strcmp(argv[i], "-r")) {
                    recursive = true;
                } if (!strcmp(argv[i], "--safe")) {
                    std::cout << "cp: skipping already existing files" << std::endl;
                    safe = true;
                }
            }
        }
    }

    if (recursive == false) {
        try {
            std::filesystem::copy_file(
                argv[1], argv[2],
                safe ? std::filesystem::copy_options::skip_existing :
                       std::filesystem::copy_options::overwrite_existing
            );
        } catch (const std::filesystem::filesystem_error& e) {
            std::cout << "cp: failed to copy file" << std::endl;
            std::cout << e.what() << std::endl;
        }
    } else {
        try {
            std::filesystem::copy(
                argv[1], argv[2],
                std::filesystem::copy_options::recursive |
                (safe ? std::filesystem::copy_options::skip_existing :
                        std::filesystem::copy_options::overwrite_existing)
            );
        } catch (const std::filesystem::filesystem_error& e) {
            std::cout << "cp: failed to copy dir" << std::endl;
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
