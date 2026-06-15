#pragma once
#include <string>
#include <filesystem>

#define loop while(true)

namespace tiniest {
    /*
    * Loop through an array and find a string inside of it.
    *
    * Arguments:
    *  char* haystack[] - array to look in,
    *  int haystack_lenght - lenght of the haystack,
    *  std::string needle - what to find,
    *  int skip_ahead = 0 - how many members of the array to skip,
    */
    static inline bool is_in_scarr(
        char* haystack[],
        int haystack_lenght,
        std::string needle,
        int skip_ahead = 0
    ) {
        for (int i = skip_ahead; i < haystack_lenght; i++) {
            if (haystack[i] == needle) {
                return true;
            }
        }

        return false;
    }

    static inline std::string get_pwd() {
        return std::filesystem::current_path();
    }
}
