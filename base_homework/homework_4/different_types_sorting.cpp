#include <iostream>
#include <array>
#include <limits>
#include <cmath>
#include "log.h"

template <size_t N>
static void sort(std::array<uint32_t,N> & array) {
	//selection sort
	for (size_t i=0; i < array.size(); ++i) {
		size_t j=i;
		for (size_t k=i; k < array.size(); ++k) {
			if (array.at(j) < array.at(k)) {
				j = k;
			}
		}
		std::swap(array.at(i), array.at(j));
	}
}

template <size_t N>
static void sort(std::array<double,N> & array) {
	//bubble sorting
	for (size_t i=0; i < array.size(); ++i) {
		for (size_t k=i; k < array.size(); ++k) {
			bool is_values_equal = std::fabs(array.at(i)-array.at(k))
				< std::numeric_limits<double>::epsilon();
			if (!is_values_equal && array.at(i) < array.at(k)) {
				std::swap(array.at(i),array.at(k));
			}
		}
	}
}

template <size_t N>
static void sort_symbols(std::array<char,N> & char_array
		,std::array<char,N> & sorted_char_array
		,const char& lower_threshold
		,const char& upper_threshold) {
	size_t sort_index{};
	for (size_t i=0; i < char_array.size(); ++i) {
		if (char_array.at(i) < lower_threshold || char_array.at(i) > upper_threshold) {
			continue;
		}
		size_t j=i;
		for (size_t k=i; k < char_array.size(); ++k) {
			if (char_array.at(k) < lower_threshold || char_array.at(k) > upper_threshold) {
				continue;
			}
			if (char_array.at(j) < char_array.at(k)) {
				j = k;
			}
		}
		sorted_char_array.at(sort_index++) = char_array.at(j);
		std::swap(char_array.at(i), char_array.at(j));
	}
}

template <size_t N>
static void sort(std::array<char,N> & char_array
	,std::array<char,N> & sorted_char_array) {
	sort_symbols(char_array, sorted_char_array, 'A', 'Z');
	sort_symbols(char_array, sorted_char_array, 'a', 'z');
	sort_symbols(char_array, sorted_char_array, '0', '9');
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
	sort(uint_array);
	log_array(uint_array);

	//double
	std::array<double,k_size> double_array;
	std::cout << "Enter " << k_size << " double digits" << '\n';
	for (size_t index=0; index < double_array.size(); ++index) {
		console_read(double_array.at(index));
	}
	sort(double_array);
	log_array(double_array);
	std::cout << '\n';

	//char
	std::array<char,k_size> char_array;
	std::cout << "Enter " << k_size << " char symbols" << '\n';
	for (size_t index=0; index < char_array.size(); ++index) {
		console_read(char_array.at(index));
	}
	std::array<char,k_size> sorted_array;
	sort(char_array,sorted_array);
	log_array(sorted_array);
	return 0;
}
