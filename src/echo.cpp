#include <iostream>

/*
 * The `echo` command prints all arguments after
 * argv[0] to the console, then prints a newline.
 *
 * If you give no arguments to the command, it
 * simply prints a plain newline, like this:
 *  $ echo
 *
 *  $
 */

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i];
    }
    std::cout << std::endl;

    return 0;
}
