#include <iostream>
#include <cmath>
#include "log.h"

int main() {
    const std::string k_tag {"main.cpp: "};
    int a{};
    log_info(k_tag + "To start solution of the quadratic equation, enter coefficients");
    log_info(k_tag + "Enter 'a' coefficient:");
    console_read(a);
    if (a == 0) {
        log_error(k_tag + "'a' coefficient is less than 0. Try again");
        return 1;
    }
    int b{};
    log_info(k_tag + "Enter 'b' coefficient:");
    console_read(b);
    int c{};
    log_info(k_tag + "Enter free member 'c':");
    console_read(c);
    long long discriminant = (b*b) - (4*a*c);
    log_debug(k_tag + "Discriminant is: ", discriminant);
    if (discriminant < 0) {
        log_info(k_tag + "Equation has no real solutions");
        return 0;
    }
    if (discriminant == 0) {
        long long first_root = (-b)/(2*a);
        log_info(k_tag + "Equation has only one root:");
        log_info(k_tag + "x1 = ", first_root);
        return 0;
    }
    log_info(k_tag + "Equation has two roots:");
    long long first_root = ((-b)+(std::sqrt(discriminant)))/(2*a);
    log_info(k_tag + "x1 = ", first_root);
    long long second_root = ((-b)-(std::sqrt(discriminant)))/(2*a);
    log_info(k_tag + "x2 = ", second_root);
}
