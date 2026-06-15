#include <iostream>
#include "lib.hpp"

/*
 * The `pwd` command prints the current working dir.
 */

int main() {
    std::string path;
    path = tiniest::get_pwd();
    std::cout << path << std::endl;

    return 0;
}
