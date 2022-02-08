#include <iostream>
#include <log.h>

struct Array {
	void log_array(const std::string& message) const noexcept;
	constexpr static size_t m_size{4};
	char m_array[m_size][m_size];
};

void Array::log_array(const std::string& message) const noexcept {
	std::cout << message << '\n';
	for (size_t i=0; i < Array::m_size; ++i) { 
		for (size_t j=0; j < Array::m_size; ++j) { 
			std::cout << m_array[i][j];
		}
	}
	std::cout << '\n';
}

void convert_message(Array& array, const bool& conversion_status) noexcept {
	constexpr char key{3};
	for (auto* elem : array.m_array) {
		if (!elem) {
			log_debug("Pointer points to nullptr");
			return;
		}
		//true - encryption, false - decryption
		if(!conversion_status) {
			*elem -= key;
			continue;
		}
		//check for UB during intended encryption
		const bool is_encription_possible = *elem+key > '\0';
		if (!is_encription_possible) {
			log_debug("Encryption is immpossible for this symbol: ", *elem);
			return;
		}
		//Caesar`s encryption
		*elem += key;
	}
	array.log_array("Here is converted array:");
	return;
}

int main() {
	Array array_base;
	constexpr size_t array_dimension = Array::m_size*Array::m_size;
	std::cout << "Enter " << array_dimension << " symbols for encryption" << '\n';
	console_read(array_base.m_array);
	array_base.log_array("Here is entered array:");
	Array array_copy = array_base;
	
	bool conversion_status{true};
	convert_message(array_copy, conversion_status);
	
	conversion_status = false;
	convert_message(array_copy, conversion_status);
    return 0;
}
