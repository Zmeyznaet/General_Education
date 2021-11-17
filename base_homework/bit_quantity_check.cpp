#include <iostream>
#include <bitset>

int main() {
    int value{};
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter number" << '\n';
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Something went wrong. Try again" << '\n';
        return 1;
    }
    if (value < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Number is negative. Try again" << '\n';
        return 1;
    }
    int bit_counter{};
    while (value != 0) {
        constexpr int one_position_shift{1};
        constexpr int last_bit_checker{1};
        if (value & last_bit_checker) {
            ++bit_counter;
        }
        value >>= one_position_shift;
    }
    std::cout << __FILE__ << ':' << __LINE__ << ':' << 
        " The quantity of bits is: " << bit_counter << '\n';
    return 0;
}
