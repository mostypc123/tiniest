#include <sys/stat.h>
#include <iostream>
#include <cstring>

/*
 * The `mkdir` command creates dirs.
 * insert big brain meme here
 *
 * The tiniest implementation of mkdir has the -p flag.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "mkdir: need to specify dir to create" << std::endl;
        return 2;
    }

    bool exist_ok = false;
    std::string dir = argv[1];
    if (!strcmp(argv[1], "-p")) {
        if (argc == 2) {
            std::cout << "mkdir: need to specify dir to create" << std::endl;
            return 2;
        }
        exist_ok = true;
        dir = argv[2];
    }

    if (exist_ok) {
        mkdir(dir.c_str(), 0755);
    } else {
        if (mkdir(dir.c_str(), 0755) != 0) {
            perror("mkdir");
            return 1;
        }
    }

    return 0;
}
