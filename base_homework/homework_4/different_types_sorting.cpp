#include <iostream>
#include <array>
#include <cmath>
#include <functional>
#include "log.h"

template <typename T>
static bool greater_comparator (T first_value, T second_value) noexcept {
	return first_value > second_value;
}

template <typename T>
static bool less_comparator (T first_value, T second_value) noexcept {
	return first_value < second_value;
}

template <size_t N>
static void sort(std::array<uint32_t,N> & array, std::function<bool(char,char)> comparator) noexcept {
	//selection sort
	for (size_t i=0; i < array.size(); ++i) {
		size_t j=i;
		for (size_t k=i; k < array.size(); ++k) {
			if (comparator(array.at(j),array.at(k))) {
				j = k;
			}
		}
		std::swap(array.at(i), array.at(j));
	}
}

template <size_t N>
static void sort(std::array<double,N> & array, std::function<bool(char,char)> lambda) noexcept{
	//bubble sorting
	for (size_t i=0; i < array.size(); ++i) {
		for (size_t k=i; k < array.size(); ++k) {
			bool is_values_equal = std::fabs(array.at(i)-array.at(k))
				< std::numeric_limits<double>::epsilon();
			if (!is_values_equal && lambda(array.at(i),array.at(k))) {
				std::swap(array.at(i),array.at(k));
			}
		}
	}
}

template <size_t N>
static void sort_char_symbols(std::array<char,N> & char_array
	,const char& lower_threshold
	,const char& upper_threshold) noexcept {
	//selection sort
	for (size_t i=0; i < char_array.size(); ++i) {
		size_t j=i;
		for (size_t k=i; k < char_array.size(); ++k) {
			if (char_array.at(k) < lower_threshold || char_array.at(k) > upper_threshold) {
				continue;
			}
			if (char_array.at(j) < char_array.at(k)) {
				j = k;
			}
		}
		std::swap(char_array.at(i), char_array.at(j));
	}
}

template <size_t N>
static void sort(std::array<char,N> & char_array) noexcept {
	sort_char_symbols(char_array, 'A', 'Z');
	sort_char_symbols(char_array, 'a', 'z');
	sort_char_symbols(char_array, '0', '9');
}

template <typename T, size_t N>
static void log_array(std::array<T, N> array) noexcept {
	std::cout << "Here is your array" << '\n';
	for (size_t index = 0; index < array.size(); ++index) { 
		std::cout << array.at(index) << ' ';
	}
	std::cout << '\n';
}

int main() {
	constexpr size_t k_size = 5;
	//unsigned int
	std::array<uint32_t,k_size> uint_array;
	std::cout << "Enter " << k_size << " unsigned digits" << '\n';
	for (size_t index=0; index < uint_array.size(); ++index) {
		console_read(uint_array.at(index));
	}
	sort(uint_array, greater_comparator<char>);
	log_array(uint_array);

	//double
	std::array<double,k_size> double_array;
	std::cout << "Enter " << k_size << " double digits" << '\n';
	for (size_t index=0; index < double_array.size(); ++index) {
		console_read(double_array.at(index));
	}
	sort(double_array, [](char first_elem, char second_elem){return first_elem > second_elem;});
	log_array(double_array);
	std::cout << '\n';

	//char
	std::array<char,k_size> char_array;
	std::cout << "Enter " << k_size << " char symbols" << '\n';
	for (size_t i=0; i < char_array.size(); ++i) {
		char tmp;
		console_read(tmp);
		if (tmp < '0' || tmp > 'z') {
			continue;
		}
		if (tmp > '9' && tmp < 'A') {
			continue;
		}
		if (tmp > 'Z' && tmp < 'a') {
			continue;
		}
		char_array.at(i) = tmp;
	}
	sort(char_array);
	log_array(char_array);
	return 0;
}
