#include <iostream>
#include <cmath>

int main() {
    int a{};
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " To start solution of the quadratic equation, enter coefficients" << '\n';
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter 'a' coefficient:" << '\n';
    if (!(std::cin >> a)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Something went wrong. Try again" << '\n';
        return 1;
    }
    if (a < 1) {
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " 'a' coefficient is less than 0. Try again" << '\n';
        return 1;
    }
    int b{};
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " To start solution of the quadratic equation, enter coefficients" << '\n';
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter 'b' coefficient:" << '\n';
    if (!(std::cin >> b)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Something went wrong. Try again" << '\n';
        return 1;
    }
    int c{};
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " To start solution of the quadratic equation, enter coefficients" << '\n';
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Enter free member 'c':" << '\n';
    if (!(std::cin >> c)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << __FILE__ << ':' << __LINE__ << ':' <<
            " Something went wrong. Try again" << '\n';
        return 1;
    }
    long long discriminant = (b*b) - (4*a*c);
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Discriminant is: " << discriminant << '\n';
    if (discriminant < 0) {
        std::cout << __FILE__ << ':' << __LINE__ <<
            ':' << " Equation has no real solutions" << '\n';
        return 0;
    }
    if (discriminant == 0) {
        long long first_root = (-b)/(2*a);
        std::cout << __FILE__ << ':' << __LINE__ <<
            ':' << " Equation has only one root: " << '\n';
        std::cout << __FILE__ << ':' << __LINE__ <<
            ':' << " x1 = " << first_root << '\n';
        return 0;
    }
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " Equation has two roots: " << '\n';
    long long first_root = ((-b)+(std::sqrt(discriminant)))/(2*a);
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " x1 = " << first_root << "  ";
    long long second_root = ((-b)-(std::sqrt(discriminant)))/(2*a);
    std::cout << __FILE__ << ':' << __LINE__ <<
        ':' << " x2 = " << second_root << '\n';
}
