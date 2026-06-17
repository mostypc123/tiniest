#include <fstream>
#include <iostream>
#include <unistd.h>

/*
 * The `touch` command creates a new file.
 */
namespace tiniest {
    static inline int touch(std::string file_) {
        if (access(file_.c_str(), F_OK) == 0) {
            std::cout << "touch: file already exists" << std::endl;
            return 1;
        }

        std::ofstream file(file_);
        if (!file.is_open()) {
            std::cout << "touch: failed to open " << file_ << std::endl;
            return 1;
        }
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "touch: you must specify the file to create." << std::endl;
        return 2;
    }

    for (int i = 1; i < argc; i++) {
        if (tiniest::touch(argv[i]) == 1) {
            std::cout << "touch: failed to create " << argv[i] << std::endl;
            return 1;
        }
    }

    return 0;
}
