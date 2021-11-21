#include <iostream>
#include "log.h"

int main() {
    // first variant
    const std::string k_tag {__FILE__ ": "};
    constexpr size_t k_size{5};
    log_info(k_tag + "Enter string (no more than 4 symbols):");
    char string[k_size];
    std::cin.getline(string, k_size);
    log_info(k_tag + "Here is result string: ");
    for (size_t i = 0; i < k_size/2; ++i) {
        constexpr size_t last_char_elem = k_size-2;
        auto tmp = string[last_char_elem-i];
        string[last_char_elem-i] = string[i];
        string[i] = tmp;
    }
    std:: cout << string << '\n';

    // second variant
    const std::string k_tag {__FILE__ ": "};
    log_info(k_tag + "Enter string (no more than 4 symbols):");
    char string[k_size];
    std::cin.getline(string, k_size);
    log_info(k_tag + "Here is result string: ");
    char result_string[k_size]{"Vasa"};
    for (size_t index = 0; index < k_size-1 ; ++index) {
        constexpr size_t last_elem_index{k_size-2};
        result_string[last_elem_index-index] = string[index];
    }
    std:: cout << result_string << '\n';

    //third variant
    const std::string k_tag {__FILE__ ": "};
    log_info(k_tag + "Enter string");
    std::string string_new;
    console_read(string_new);
    log_info(k_tag + "Here is result string: ");
    for (size_t index = 0; index < string_new.length()/2; ++index) {
        auto tmp = string[string_new.length()-1-index];
        string[string_new.length()-1-index] = string[index];
        string[index] = tmp;
    }
    std:: cout << string << '\n';

    // fourth variant
    const std::string k_tag {__FILE__ ": "};
    log_info(k_tag + "Enter string");
    std::string string_one;
    console_read(string);
    log_info(k_tag + "Here is result string: ");
    const auto string_middle_iterator = std::next(string_one.begin(), string_one.length()/2);
    for (auto i = string_one.begin(), j = string_one.end()-1; i != string_middle_iterator; ++i, j--) {
        auto tmp = *j;
        *j = *i;
        *i = tmp;
    }
    std:: cout << string << '\n';
    return 0;
}
