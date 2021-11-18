#include <iostream>

int main() {
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter a string:" << '\n';
    std::string str;
    if (!(std::cin >> str)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cerr << "Something went wrong when read input. Try again" << '\n';
        return 1;
    }
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Result string is:" << '\n';
    std::string result_str;
    for (auto str_iterator = str.end()-1, result_str_iterator = result_str.begin();
        str_iterator >= str.begin(); --str_iterator, ++result_str_iterator) {
        *result_str_iterator = *str_iterator;
        std::cout << *result_str_iterator;
    }
    std::cout << '\n';
    return 0;
}
