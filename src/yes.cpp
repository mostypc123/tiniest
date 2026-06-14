#include <iostream>
#include <cstring>
#include "lib.hpp"

/*
 * The `yes` command is used to repeatedly
 * print a string to the terminal. This is
 * very useful when a command asks for
 * confirmation but it has no --yes/--no
 * flag. For example, we can use it like this:
 * $ yes | pacman -S vim
 *
 * Note: pacman has a --noconfirm flag.
 *
 * In `tiniest`, when `yes` is called with
 * argv[0] being `no`, the default value to
 * print (`y`) becomes `n`.
 */

int main(int argc, char* argv[]) {
    std::string to_print = "y";

    // as mentioned above
    if (!strcmp(argv[0], "no")) to_print = "n";
    if (argc != 1) to_print = argv[1];

    loop {
        std::cout << to_print << "\n";
    }

    return 0;
}
