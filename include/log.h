#pragma once
#include <iostream>
#include <limits>

inline void log_info (const std::string message) noexcept {
        std::cout << message << '\n';
}

template <typename T>
inline void log_info (const std::string message, const T& value) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cout << *iterator;
    }
    std::cout << value << '\n';
}

template <typename T>
inline int log_info (const std::string message, const T* value) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cout << *iterator;
    }
    if (value == nullptr) {
        log_error("Error. value == ", value);
        return 1;
    }
    std::cout << *value << '\n';
    return 0;
}

inline void log_debug (const std::string message) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cout << *iterator;
    }
    std::cout << '\n';
}

template <typename T>
inline void log_debug (const std::string message, const T& value) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cout << *iterator;
    }
    std::cout << value << '\n';
}

template <typename T>
inline int log_debug (const std::string message, const T* value) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cout << *iterator;
    }
    if (value == nullptr) {
        log_error("Error. value == ", value);
        return 1;
    }
    std::cout << *value << '\n';
    return 0;
}

inline void log_error (const std::string message) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cerr << *iterator;
    }
    std::cerr << '\n';
}

template <typename T>
inline void log_error (const std::string message, const T& value) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cerr << *iterator;
    }
    std::cerr << value << '\n';
}

template <typename T>
inline int log_error (const std::string message, const T* value) noexcept {
    for (auto iterator = message.begin(); iterator < message.end(); ++iterator) {
        std::cerr << *iterator;
    }
    if (value == nullptr) {
        log_error("Error. value == ", value);
        return 1;
    }
    std::cerr << *value << '\n';
    return 0;
}

template <typename T>
inline int console_read (T& value) noexcept {
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cerr << "Something went wrong. Try again" << '\n';
        return 1;
    }
    return 0;
}

template <typename T>
inline int console_read (T* value) noexcept {
    if (value == nullptr) {
        log_error("Error. value == ", value);
        return 1;
    }
    if (!(std::cin >> *value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cerr << "Something went wrong. Try again" << '\n';
        return 1;
    }
    return 0;
}
