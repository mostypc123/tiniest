#include <signal.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>

/*
 * The `kill` command kills a process. Use --graceful to send
 * SIGTERM and --interrupt SIGINT. Otherwise just sends SIGKILL.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "kill: need to specify whom to kill" << std::endl;
        return 2;
    }

    int signal = SIGKILL;
    int to_kill = std::stoi(argv[1]);

    if (argc > 2) {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], "--graceful")) {
                signal = SIGTERM;
            }
            if (!strcmp(argv[i], "--interrupt")) {
                signal = SIGINT;
            }
        }
    }

    int result = kill(to_kill, signal);
    if (result == -1) {
        perror("kill");
        return 1;
    }
    return 0;
}
