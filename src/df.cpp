#include <iostream>
#include <filesystem>

/*
 * The `df` command shows the file size of a file.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "df: missing file" << std::endl;
        return 2;
    }

    try {
        if (std::filesystem::is_directory(argv[1])) {
            std::cerr << "df: tiniest currently does not support recursion in df" << std::endl;
            return 2;
        }

        std::uintmax_t size = std::filesystem::file_size(argv[1]);
        std::cout << argv[1] << "\t" << size << " B" << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "df: " << argv[1] << " does not exist" << std::endl;
        return 1;
    }
    return 0;
}
