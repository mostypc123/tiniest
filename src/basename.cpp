#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstring>

/*
 * The `basename` command prints only the filename
 * from an absolute path.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "basename: you must specify a file" << std::endl;
        return 2;
    }

    const char* path = argv[1];
    const char* slash = strrchr(path, '/');
    const char* basename = slash ? slash + 1 : path;

    std::cout << basename << std::endl;
    return 0;
}
