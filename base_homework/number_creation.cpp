#include <iostream>
#include <string>

int main() {
    int quantity{};
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter a quantity of numbers to check" << '\n';
    if (!(std::cin >> quantity)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Something went wrong. Try again" << '\n';
        return 1;
    }
    if (quantity < 0) {
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Quantity of numbers is less than 0." 
                "Try again" << '\n';
        return 1;
    }
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter check numbers" << '\n';
    uint32_t number{};
    std::string string_result_number{""};
    for (int i=1; i <= quantity; ++i) {
        if (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
                " Something went wrong. Try again" << '\n';
            return 1;
        }
        if (number < 0) {
            std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
                " Number is less than 0. Try again" << '\n';
            return 1;
        }
        if (number%3 == 0) {
            string_result_number += std::to_string(number);
            continue;
        }
        string_result_number = std::to_string(number) + 
            string_result_number;
    }
    const uint32_t int_result_number = std::stoi(string_result_number);
    if (int_result_number%3 == 0) {
        std::cout << __FILE__ << ':' << __LINE__ << ':' <<
            " Yes" << '\n';
        return 0;
    }
    std::cout << __FILE__ << ':' << __LINE__ << ':' <<
        " No" << '\n';
    return 0;
}
