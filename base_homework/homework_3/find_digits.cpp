#include <iostream>
#include "log.h"

int main() {
    //first variant
    log_info("Enter string");
    constexpr uint16_t k_size{std::numeric_limits<uint16_t>::max()};
    char string[k_size]{};
    std::cin.getline(string, k_size);
    std::cout << "is digit ";
    for (auto& elem : string) {
        if (elem >= '0' && elem <= '9') {
            std::cout << elem << ' ';
        }
    }
    std::cout << '\n';

    //second variant
    log_info("Enter string");
    std::string new_string;
    console_read(new_string);
    for (uint32_t index=0; index < new_string.size(); ++index) {
        if (new_string.at(index) <= '0' || new_string.at(index) >= '9') {
            new_string.erase(index, 1);
            --index;
        }
    }
    std::cout << "is digit ";
    for (auto elem : new_string) {
        std::cout << elem << ' ';
    }
    log_info("\n");

    //third variant
    log_info("Enter string");
    std::string string;
    console_read(string);
    std::cout << "is digit ";
    for (auto iterator=string.begin(); iterator != string.end(); ++iterator) {
        if (*iterator >= '0' && *iterator <= '9') {
            std::cout << *iterator << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
