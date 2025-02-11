#pragma once
#include <iostream>
#include <vector>

template<class T, class container = std::vector<T>>

class Stack {
public:
    using value_type = typename container::value_type;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = typename container::size_type;

    Stack(size_type size);
    Stack(const Stack& other);
    Stack(Stack&& other);
    Stack& operator=(const Stack& other) noexcept;
    Stack& operator=(Stack&& other) noexcept;
    ~Stack() = default;

    void push(const_reference val);
    void pop();
    reference top();
    const_reference top() const;
    size_type size() const;
    bool empty();
    reference operator[](size_type index);
    const_reference operator [](size_type index) const;
private:
    container obj;
};

#include "stack.hpp"