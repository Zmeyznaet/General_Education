#pragma once

template <class T>
class Stack final {
    public:
        Stack();
        Stack(const Stack&);
        Stack& operator=(const Stack&);
        Stack(Stack&& rhs);
        Stack& operator=(Stack&& rhs);
        virtual ~Stack() noexcept;
        bool empty() noexcept;
        void pop();
        void push(const T elem);
        size_t size() const;
        T* top() const;

    private:
        void array_reorder(const size_t size, const int is_method_push);
        size_t m_array_size{};
        T* m_array;
};

#include "../lib/stack.cpp"
