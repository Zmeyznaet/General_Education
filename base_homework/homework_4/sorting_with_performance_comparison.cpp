#include <iostream>
#include <array>
#include <chrono>
#include <random>
#include "log.h"

int main() {
    constexpr uint64_t ksize{5};
    std::array<int32_t,ksize>array_1{};
    // log_info("Enter five integer elements"); // for user input
    std::mt19937 random_32_bit_generator;
    random_32_bit_generator.seed(std::time(nullptr)); 
    // random generation
    for (auto& elem : array_1) {
        elem = random_32_bit_generator();
    }
    // user input
    // for (auto elem : array_1) {
    //     if(!(std::cin >> elem)) {
    //         std::cin.clear();
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //         log_error("Wrong size or type of the value. Try again");
    //         return 1;
    //     }
    // }
    std::array<int32_t,ksize>array_2 = array_1;
    //bubble-sorting
    auto initial_time_point = std::chrono::steady_clock::now();
    for (uint64_t j=0; j < ksize; ++j) {
        for (uint64_t i=0; (i+1)<ksize; ++i) {
            if(array_1.at(i) > array_1.at(i+1)) {
                //TODO:std::swap implement
                std::swap(array_1.at(i+1), array_1.at(i));
                // instead of swap function
                // auto tmp = array_1.at(i+1);
                // array_1.at(i+1) = array_1.at(i);
                // array_1.at(i) = tmp;
            }
        }
    }
    auto end_time_point = std::chrono::steady_clock::now();
    log_info("Here is an array after bubble-sorting:");
    for (auto elem : array_1) {
        std::cout << elem << '\n';
    }
    std::chrono::duration<double> elapsed_seconds = end_time_point-initial_time_point;
    log_info("Here is elapsed seconds for bubble-sorting:", elapsed_seconds.count());
    //selection sort
    initial_time_point = std::chrono::steady_clock::now();
    for(uint32_t i=0; i < ksize; i++){
        uint32_t j = i;
        for(uint32_t k=i; k < ksize; k++){
            if(array_2.at(j) > array_2.at(k)){
                j = k;
            }
        }
        auto tmp = array_2.at(i);
        array_2.at(i) = array_2.at(j);
        array_2.at(j) = tmp;
    }
    end_time_point = std::chrono::steady_clock::now();
    log_info("Here is an array after selection sort:");
    for (auto elem : array_2) {
        std::cout << elem << '\n';
    }
    elapsed_seconds = end_time_point-initial_time_point;
    log_info("Here is elapsed seconds for selection sort: ", elapsed_seconds.count());
}