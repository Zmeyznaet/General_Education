#include <iostream>
#include "stack.h"

template <class T>
Stack<T>::Stack() = default;

template <class T>
Stack<T>::Stack(const Stack&) = default;

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>&) = default;

template <class T>
Stack<T>::Stack(Stack&& rhs) {
    m_array_size = rhs.m_array_size;
    rhs.m_array_size = 0;
    delete m_array;
    m_array = rhs.m_array;
    rhs.m_array = nullptr;
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& rhs) {
    m_array_size = rhs.m_array_size;
    rhs.m_array_size = 0;
    delete m_array;
    m_array = rhs.m_array;
    rhs.m_array = nullptr;
    return *this;
}

template <class T>
Stack<T>::~Stack() noexcept = default;

template <class T>
bool Stack<T>::empty() noexcept{
    constexpr bool is_empty{true};
    if(!m_array) {
        return is_empty;
        std::cerr << __FILE__ << ":" << __LINE__ << " Array is not valid" << '\n';
    }
    for(T* array_copy = m_array; array_copy != nullptr; ++array_copy) {
        if(*array_copy != 0) {
            std::cout << __FILE__ << ":" << __LINE__ << " Array is not empty" << '\n';
            return !is_empty;
        }
    }
    std::cout << __FILE__ << ":" << __LINE__ << " Array is empty" << '\n';
    return is_empty;
}

template <class T>
void Stack<T>::pop() {
    constexpr size_t k_one_elem{1};
    if(size() == k_one_elem) {
        std::cerr << __FILE__ << ":" << __LINE__ << " Array is not valid" << '\n';
        return;
    }
    constexpr int is_method_push = 0;
    array_reorder(--m_array_size, is_method_push);
    std::cout << __FILE__ << ":" << __LINE__ << " Top element was popped" << '\n';
}

template <class T>
void Stack<T>::push(const T elem) {
    if(constexpr size_t k_no_elem=0; size() == k_no_elem) {
        ++m_array_size;
        const size_t array_index = m_array_size - 1;
        m_array = new T[m_array_size]{};
        *(m_array+array_index) = elem;
        std::cout << __FILE__ << ":" << __LINE__ << " Element " << array_index << " added" << '\n';
        return;
    }
    ++m_array_size;
    const size_t array_index = m_array_size - 1;
    const int is_method_push = -1;
    array_reorder(m_array_size, is_method_push);
    *(m_array+array_index) = elem;
    std::cout << __FILE__ << ":" << __LINE__ << " Element " << array_index << " added" << '\n';
}

template <class T>
size_t Stack<T>::size() const {
    return m_array_size;
}

template <class T>
T* Stack<T>::top() const {
    if(!m_array) {
        std::cerr << __FILE__ << ":" << __LINE__ << " Array is not valid" << '\n';
        return nullptr;
    }
    size_t array_index{size()-1};
    std::cout << __FILE__ << ":" << __LINE__ << " Top element " << array_index << " returned" << '\n';
    return m_array + array_index;
}

template <class T>
void Stack<T>::array_reorder(const size_t size, const int is_method_push){
    if(!m_array) {
        std::cerr << __FILE__ << ":" << __LINE__ << " Array is not valid" << '\n';
        return;
    }
    T* m_array_end = m_array + size + is_method_push;
    T* reordered_array_origin = new T[size]{};
    T* reordered_array_copy = reordered_array_origin;
    for(;m_array != m_array_end; ++m_array, ++reordered_array_copy){
        *reordered_array_copy = *m_array;
    }
    std::cout << __FILE__ << ":" << __LINE__ << " Array was successfully reordered" << '\n';
    m_array = reordered_array_origin;
}
