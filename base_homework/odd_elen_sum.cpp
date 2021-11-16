#include <iostream>
#include <vector>

int main() {
    int size{};
    std::cout << "Enter quantity of elements you want" << '\n';
    if (!(std::cin >> size)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr << "Something went wrong when read input. Try again" << '\n';
        return 1;
    }
    constexpr auto min_size{1};
    constexpr auto max_size{50};
    if (size < min_size || size > max_size) {
        std::cerr << "Size is out of range. Try again" << '\n';
        return 1;
    }
    std::vector<int>vector;
    std::cout << "Enter elements you want" << '\n';
    for (auto index=0; index < size; ++index) {
        int value{};
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cerr << "Something went wrong when read input. Try again" << '\n';
            return 1;
        }
        constexpr int min_value{-60};
        constexpr int max_value{90};
        if (value < min_value || value > max_value) {
            std::cerr << "Value is out of range. Try again" << '\n';
            return 1;
        }
        vector.push_back(value);
    }
    std::cout << "Here is a list of array" << '\n';
    for (auto elem : vector) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    int sum{};
    std::cout << "Here is a sum of odd elements: " << '\n';
    for (auto elem : vector) {
        sum += elem & 1 ? elem : 0;
    }
    std::cout << sum;
    std::cout << '\n';
    return 0;
}
