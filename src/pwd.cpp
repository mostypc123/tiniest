#include <filesystem>
#include <iostream>

/*
 * The `pwd` command prints the current working dir.
 */

int main() {
    std::string path;
    path = std::filesystem::current_path();
    std::cout << path << std::endl;

    return 0;
}
