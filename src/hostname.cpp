#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>

/*
 * The `hostname` command sets or reads the current hostname.
 * It can set a temporary or a persistent hostname, and show
 * the current one if no arguments were specified.
 *
 * $ hostname
 * myhost
 * $ hostname hello
 * set hostname to 'hello'
 * $ hostname
 * hello
 * $ hostname --temp hellohello
 * set temporary hostname to 'hellohello'
 * $ reboot
 * ...
 * $ hostname
 * hello
 */

int main(int argc, char* argv[]) {
    // show hostname
    if (argc == 1) {
        char buf[256];
        gethostname(buf, sizeof(buf));
        std::cout << buf << std::endl;
        return 0;
    }

    // temp hostname handling
    if (!strcmp(argv[1], "--temp")) {
        if (argc == 2) {
            std::cout << "hostname: need to specify hostname to set" << std::endl;
            return 2;
        }

        std::fstream hostname_file("/proc/sys/kernel/hostname");
        hostname_file << argv[2];
        hostname_file.close();

        std::cout << "set temporary hostname to '" << argv[2] << "'" << std::endl;
        return 0;
    }

    constexpr const char* HOSTNAME_FILE = "/etc/hostname";
    std::fstream hostname_file(HOSTNAME_FILE);
    hostname_file << argv[1];
    hostname_file.close();
    // also write to the temp host file
    std::fstream hostnamet_file("/proc/sys/kernel/hostname");
    hostnamet_file << argv[1];
    hostnamet_file.close();
    std::cout << "set hostname to '" << argv[1] << "'" << std::endl;

    return 0;
}
