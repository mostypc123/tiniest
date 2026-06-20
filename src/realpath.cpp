#include <iostream>
#include <filesystem>

/*
 * The realpath command shows the absolute path of a file,
 * following symlinks.
 */

int main(int argc, char* argv[]) {
    (void)argc;

    std::string operand = argv[1] ? argv[1] : ".";
    try {
        std::string result = std::filesystem::canonical(operand).string();
        std::cout << result << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "An error occured: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
