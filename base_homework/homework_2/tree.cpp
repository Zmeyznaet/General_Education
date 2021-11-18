#include <iostream>

int main() {
    std::cout << __FILE__ << ':' << __LINE__ << ": Enter an odd number of stars" << '\n';
    int value{};
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr << "Something went wrong when read input. Try again" << '\n';
        return 1;
    }
    if (value < 1) {
        std::cerr << __FILE__ << ':' << __LINE__ << " Such tree cannot be built"
            " (number of stars are less than 0). Try again" << '\n';
        return 1;
    }
        if (value%2 == 0) {
        std::cerr << __FILE__ << ':' << __LINE__ << " Such tree cannot be built"
            " (number is even). Try again" << '\n';
        return 1;
    }
    for (int i = 1; i <= value; i+=2) {
        std::cout << std::string((value-i)/2, ' ');
        std::cout << std::string(i, '*') << '\n';
    }
    return 0;
}
