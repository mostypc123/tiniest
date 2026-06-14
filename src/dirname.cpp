#include <iostream>
#include <string>
#include <vector>
#include <cstring>

/*
 * The `dirname` command prints only the directory that
 * contains a file that is specified as an argument.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "dirname: you must specify a file" << std::endl;
        return 2;
    }

    std::vector<std::string> parts;
    char* token = std::strtok(argv[1], "/");
    while (token != nullptr) {
        parts.push_back(token);
        token = std::strtok(nullptr, "/");
    }

    if (parts.empty()) {
        std::cout << "." << std::endl;
        return 0;
    }

    for (size_t i = 0; i < parts.size() - 1; ++i) {
        std::cout << "/" << parts[i];
    }

    std::cout << std::endl;
    return 0;
}
