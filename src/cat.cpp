#include <iostream>
#include <fstream>

/*
 * The `cat` command reads the content of a file.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "cat: specify a file to read." << std::endl;
        return 2;
    }

    std::ifstream file(argv[1]);
    std::string text;
    while (getline(file, text)) {
        std::cout << text << std::endl;
    }
    file.close();

    return 0;
}
