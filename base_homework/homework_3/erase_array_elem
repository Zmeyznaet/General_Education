#include <iostream>
#include <array>
#include "log.h"

int main() {
    log_info("Here is an array:");
    constexpr uint64_t k_size{3};
    std::array<int32_t,k_size>array{};
    for (auto& elem : array) {
        elem = std::rand() % 6 + 1;
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    int value{};
    uint64_t count{0};
    while (count != 3) {
        log_info("Enter a number to find array element");
        console_read(value);
        for (auto& elem : array) {
            if (elem == value && elem != 0) {
                elem = 0;
                ++count;
                log_info("Elements found: ", count);
                continue;
            }
        }
    }
    return 0;
}
