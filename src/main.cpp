#include <iostream>
#include <limits>
#include "stack.h"

int main() {
    Stack<int>custom_stack;
    size_t stackSize = custom_stack.size();
    custom_stack.push(1);
    std::cout << "stackSize: " << stackSize << '\n';
    custom_stack.push(2);
    stackSize = custom_stack.size();
    std::cout << "stackSize: " << stackSize << '\n';
    bool isEmptyStack = custom_stack.empty();
    auto topStackElem = custom_stack.top();
    custom_stack.pop();
    stackSize = custom_stack.size();
    std::cout << "isEmptyStack: " << isEmptyStack << '\n';
    std::cout << "stackSize: " << stackSize << '\n';
    std::cout << "topStackElem: " << *topStackElem << '\n';
    std::cout << "All checks regarding stack was passed" << '\n';

    auto state = true;
    int intState = static_cast<int>(state);
    std::cout << std::boolalpha;
    std::cout << (bool)intState << '\n';

    auto value = std::numeric_limits<int>::max();
    std::cout << value << '\n';

    double value_1 = 7/2.0;
    std::cout << value_1 << '\n';
    double value_2 = 7/2;
    std::cout << value_2 << '\n';
}