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
            std::uintmax_t full_size = 0;
            for (const auto & entry : std::filesystem::directory_iterator(argv[1])) {
                std::uintmax_t size = std::filesystem::file_size(entry.path());
                std::cout << entry.path() << "\t" << size << " B" << std::endl;
                full_size += size;
            }
            std::cout << argv[1] << "\t" << full_size << " B" << std::endl;
            return 0;
        }

        std::uintmax_t size = std::filesystem::file_size(argv[1]);
        std::cout << argv[1] << "\t" << size << " B" << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "df: a filesystem error occured" << std::endl;
        return 1;
    }
    return 0;
}
