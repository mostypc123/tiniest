#include <iostream>
#include <filesystem>
#include <cstring>
#include "lib.hpp"

/*
 * The `ls` command lists the contents of the current dir.
 * The -a flag is used to not hide dotfiles.
 * The -l flag is used to show a list of files.
 * Note: Instead of showing the perms like drwxr-xr-x,
 *       tiniest ls shows something like 0755.
 * Note: If argv[0] is 'll', the -l flag is used automatically.
 */

int main(int argc, char* argv[]) {
    std::string dir = ".";
    if (argc > 1 && argv[1][0] != '-') {
        dir = argv[1];
    }

    bool show_all = !strcmp(argv[0], "ll");
    bool show_list = !strcmp(argv[0], "ll");

    // sort of a hack, TODO fix
    if (tiniest::is_in_scarr(argv, argc, "-la")) {
        show_all = true;
        show_list = true;
    } else if (tiniest::is_in_scarr(argv, argc, "-l")) {
        show_list = true;
    } else if (tiniest::is_in_scarr(argv, argc, "-a")) {
        show_all = true;
    }

    int counter = 0;
    try {
        if (show_list) std::cout << "name size time" << std::endl << "--------------" << std::endl;
        for (const auto & entry : std::filesystem::directory_iterator(dir)) {
            counter++;
            std::string name = entry.path().filename().string();
            if (show_all || name[0] != '.') {
                if (show_list) {
                    std::string size = "is a dir";
                    if (!entry.is_directory()) {
                        size = std::to_string(entry.file_size());
                    }
                    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                        entry.last_write_time() - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now()
                    );
                    auto tt = std::chrono::system_clock::to_time_t(sctp);
                    std::cout << name << "  " << size << "  " << tt << std::endl;
                } else {
                    std::cout << name << "  ";
                }
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "A filesystem error occured:" << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }

    if (!show_list) std::cout << std::endl;
    if (show_list) std::cout << "total " << counter << std::endl;
}
