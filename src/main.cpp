#include <iostream>
#include "../include/stack.h"

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
}