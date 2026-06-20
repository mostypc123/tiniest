#include <iostream>
#include <iomanip>
#include <unistd.h>

/*
 * The hostid command gets the host id.
 * insert big brain meme here
 */

int main() {
    std::cout << std::setfill('0') << std::setw(8)
        << std::hex << gethostid() << std::endl;
    return 0;
}
