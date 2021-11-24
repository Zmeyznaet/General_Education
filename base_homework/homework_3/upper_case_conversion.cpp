#include <iostream>
#include "log.h"

int main() {
    //first variant
    log_info("Enter string");
    constexpr uint32_t k_size{6};
    char string[k_size]{};
    std::cin.getline(string, k_size);
    for (auto& elem : string) {
        if (elem >= 'a' && elem <= 'z') {
            constexpr char conversion_coef{32};
            elem -= conversion_coef;
        }
        std::cout << elem;
    }
    std::cout << '\n';

    //second variant
    log_info("Enter string");
    std::string string;
    console_read(string);
    log_info("Here is result string:");
    for (auto& elem : string) {
        if (elem >= 'a' && elem <= 'z') {
            constexpr char conversion_coef{32};
            elem -= conversion_coef;
        }
        std::cout << elem;
    }
    std::cout << '\n';
    return 0;
}
