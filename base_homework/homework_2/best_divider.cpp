#include <iostream>
#include <vector>

int main() {
    int value{};
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr <<  __FILE__ << ':' << __LINE__ << ": Something went wrong when read input. Try again" << '\n';
        return 1;
    }
    if (value < 0) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ": Value is out of range. Try again" << '\n';
        return 1;
    }
    std::vector<int>vector;
    for (int divider=1; divider <= value; ++divider) {
        if (value%divider == 0) {
            vector.push_back(divider);
        }
    }
    int best_divider{};
    int divider_ranks_sum{};
    for (auto iterator = vector.begin(); iterator < vector.end(); ++iterator) {
        constexpr int last_rank_divider{10};
        for (int divider_checker = *iterator; divider_checker != 0; divider_checker/=last_rank_divider) {
            divider_ranks_sum += (divider_checker%last_rank_divider);
        }
        if (best_divider < divider_ranks_sum) {
            best_divider = divider_ranks_sum;
        }
        divider_ranks_sum = 0;
    }
    std::cout << __FILE__ << ':' <<  __LINE__ << ": Best divider is: " << best_divider << '\n';
    return 0;
}
