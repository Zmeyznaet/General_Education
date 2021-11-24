#include <iostream>
#include "log.h"

int main() {
    //first variant
    log_info("Enter string");
    std::string string;
    console_read(string);
    for (auto iterator=string.begin(); iterator != string.end(); ++iterator) {
        if (*iterator >= 'A' && *iterator <= 'Z') {
            constexpr char conversion_coef{32};
            *iterator += conversion_coef;
        }
    }
    log_info("Here is result string:\n", string);

    //second variant
    log_info("Enter string");
    constexpr uint16_t k_size{std::numeric_limits<uint16_t>::max()};
    char string[k_size]{};
    std::cin.getline(string,k_size);
    for (auto& elem : string) {
        if (elem >= 'A' && elem <= 'Z') {
            constexpr char conversion_coef{32};
            elem += conversion_coef;
        }
    }
    log_info("Here is result string:\n", string);

    //third variant
        log_info("Enter string");
    constexpr uint16_t k_size{std::numeric_limits<uint16_t>::max()};
    char string[k_size]{};
    std::cin.getline(string,k_size);
    for (char* string_copy = string; string_copy != &string[k_size]; ++string_copy) {
        if (*string_copy >= 'A' && *string_copy <= 'Z') {
            constexpr char conversion_coef{32};
            *string_copy += conversion_coef;
        }
    }
    log_info("Here is result string:\n", string);
    return 0;
}
