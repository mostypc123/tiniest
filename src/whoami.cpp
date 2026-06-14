#include <iostream>
#include <pwd.h>
#include <unistd.h>

/*
 * The `whoami` command prints the current logged in user.
 */

int main() {
    struct passwd *pw = getpwuid(getuid());
    if (!pw) {
        std::cout << "failed to read username" << std::endl;
        return 1;
    }
    std::cout << pw->pw_name << std::endl;
    return 0;
}
