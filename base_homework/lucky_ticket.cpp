#include <iostream>

int main() {
    int value{};
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr << "Something went wrong when read input. Try again" << '\n';
        return 1;
    }
    constexpr int k_max_value{999999};
    constexpr int k_min_value{100000};
    if (value < k_min_value || value > k_max_value) {
        std::cerr << "Input value is out of range. Try again" << '\n';
        return 1;
    }
    int first_half_sum{};
    int second_half_sum{};
    for (size_t max_rank_number=6, digit_number = 1; digit_number <= max_rank_number; ++digit_number) {
        constexpr int last_rank_divider{10};
        constexpr int on_half_divider{2};
        if (digit_number <= max_rank_number/on_half_divider) {
            first_half_sum += value%last_rank_divider;
        }
        if (digit_number > max_rank_number/on_half_divider) {
            second_half_sum += value%last_rank_divider;
        }
        value/=last_rank_divider;
    }
    if (first_half_sum != second_half_sum) {
        std::cout << "You are not lucky" << '\n';
        return 0;
    }
    std::cout << "You are lucky!!!" << '\n';
}
