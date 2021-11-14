#include <iostream>
#include <vector>

int main() {
    std::string string{""};
    if (!(std::cin >> string)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std:: cerr << "Something went wrong when read input. Try again" << '\n';
        return 1;
    }
    int int_sum{};
    for(auto iterator = string.begin(); iterator != string.end(); ++iterator) {
        if(*iterator < '0' || *iterator > '9') {
            std:: cerr << "Not number. Please, enter number" << '\n';
            return 1;
        }
        //converting to int from decimal value of char
        int_sum += *iterator - '0';
    }
    std:: cout << "The sum of integers is: " << int_sum << '\n';
    int average = int_sum/string.length();
    std:: cout << "An average is: " << average << '\n';

}
