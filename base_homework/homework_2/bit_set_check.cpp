#include <iostream>

int main() {
    long long value{};
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
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Number is less than 0. Try again" << '\n';
        return 1;
    }
    long long check_number{};
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter check number" << '\n';
    if (!(std::cin >> check_number)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Something went wrong. Try again" << '\n';
        return 1;
    }
    if (check_number < 0) {
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Number is less than 0. Try again" << '\n';
        return 1;
    }
    if ((value & check_number) == 0) {
        std::cout << __FILE__ << ':' << __LINE__ << ':' <<
            " Bit was not set" << '\n';
        return 0;
    }
    std::cout << __FILE__ << ':' << __LINE__ << ':' <<
        " Bit was set" << '\n';
    return 0;
}
