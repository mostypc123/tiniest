#include <iostream>
#include <unistd.h>

/*
 * The `chroot` command is a wrapper for the chroot syscall,
 * which changes the current / dir for the running process.
 *
 * chroot <opt: dir, default .> <opt: shell, default /bin/sh>
 *
 * Note: unlike GNU chroot, tiniest chroot does not use the
 *       shell that is currently running as default.
 */

int main(int argc, char* argv[]) {
    std::string dir = ".";
    std::string shell = "/bin/sh";

    if (argc == 2) {
        // set the dir
        dir = argv[1];
    } else if (argc == 3) {
        // set the shell
        shell = argv[2];
    }

    if (dir == ".")
        std::cout << "chroot: changing to . because no dir was specified" << std::endl;


}
