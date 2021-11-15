#include <iostream>
#include <bitset>

int main() {
    int value{};
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr << "Something went wrong when read input. Try again" << '\n';
        return 1;
    }

    value = ~(value - 1);
    std::cout << value << '\n';
}
