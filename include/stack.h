#pragma once

template <class T>
class Stack final {
    public:
        Stack() = default;

        Stack(const Stack&) = default;

        Stack& operator=(const Stack&) = default;

        Stack(Stack&& rhs) {
            m_array_size = rhs.m_array_size;
            rhs.m_array_size = 0;
            delete m_array;
            m_array = rhs.m_array;
            rhs.m_array = nullptr;
        }

        Stack& operator=(Stack&& rhs) {
            m_array_size = rhs.m_array_size;
            rhs.m_array_size = 0;
            delete m_array;
            m_array = rhs.m_array;
            rhs.m_array = nullptr;
            return *this;
        }

        virtual ~Stack() noexcept = default;

        bool empty() noexcept {
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

        void pop() {
            constexpr size_t k_one_elem{1};
            if(size() == k_one_elem) {
                std::cerr << __FILE__ << ":" << __LINE__ << " Array is not valid" << '\n';
                return;
            }
            constexpr int is_method_push = 0;
            array_reorder(--m_array_size, is_method_push);
            std::cout << __FILE__ << ":" << __LINE__ << " Top element was popped" << '\n';
        }

        void push(const T elem) {
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
        
        size_t size() const {
            return m_array_size;
        }
        
        T* top() const {
            if(!m_array) {
                std::cerr << __FILE__ << ":" << __LINE__ << " Array is not valid" << '\n';
                return nullptr;
            }
            size_t array_index{size()-1};
            std::cout << __FILE__ << ":" << __LINE__ << " Top element " << array_index << " returned" << '\n';
            return m_array + array_index;
        }

    private:
        void array_reorder(const size_t size, const int is_method_push) {
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
        
        size_t m_array_size{};
        T* m_array;
};