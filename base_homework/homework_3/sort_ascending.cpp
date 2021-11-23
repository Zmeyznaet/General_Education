#include <iostream>
#include <array>
#include "log.h"

int main() {
    //first variant
    log_info("Enter value of array elem (5 elements totally):");
    constexpr uint64_t k_size{5};
    std::array<int64_t,k_size>array{};
    int64_t value{};
    for (uint64_t i = 1; i <= array.size(); ++i) {
        console_read(value);
        array.front() = value;
        for (uint64_t index=0; index+1 < array.size(); ++index) {
            if (array.at(index) > array.at(index+1)) {
                auto tmp = array.at(index);
                array.at(index) = array.at(index+1);
                array.at(index+1) = tmp;
            }
        }
    }
    log_info("Here is an array of elements:");
    for (auto elem : array) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    //second variant
    log_info("Enter value of array elem (5 elements totally):");
    constexpr uint64_t k_size{5};
    std::array<int64_t,k_size>array{};
    int64_t value{};
    for (uint64_t i = 1; i <= array.size(); ++i) {
        console_read(value);
        array.back() = value;
        for (uint64_t index=array.size()-1; index >= 1; --index) {
            if (array.at(index) > array.at(index-1)) {
                auto tmp = array.at(index);
                array.at(index) = array.at(index-1);
                array.at(index-1) = tmp;
            }
        }
    }
    log_info("Here is an array of elements:");
    for (auto elem : array) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    //third variant
    log_info("Enter value of array elem (5 elements totally):");
    constexpr uint64_t k_size{5};
    std::array<int64_t,k_size>array{};
    int64_t value{};
    for (uint64_t i = 1; i <= array.size(); ++i) {
        console_read(value);
        array.front() = value;
        for (auto iterator=array.begin(); iterator != array.end()-1; ++iterator) {
            if (*iterator > *std::next(iterator,1)) {
                auto tmp {*std::next(iterator,1)};
                *std::next(iterator,1) = *iterator;
                *iterator = tmp;
            }
        }
    }
    log_info("Here is an array of elements:");
    for (auto elem : array) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    return 0;
}
