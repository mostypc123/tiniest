#include <iostream>
#include <fstream>

/*
 * The `nl` command is similar to `cat` - it numbers lines of a file.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "nl: no file specified" << std::endl;
        return 2;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "nl: failed to read " << argv[1];
        return 1;
    }

    std::string text;
    int line = 1;
    while (getline(file, text)) {
        std::cout << " " << line << "\t" << text << std::endl;
        line++;
    }

    file.close();

    return 0;
}
