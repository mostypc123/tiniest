#include <thread>
#include <chrono>
#include <iostream>

/*
 * The `sleep` command waits for a specified time.
 */

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "sleep: you must specify a duration" << std::endl;
        return 2;
    }

    double seconds = std::stod(argv[1]);
    std::this_thread::sleep_for(std::chrono::duration<double>(seconds));

    return 0;
}
