#pragma once
#include <vector>
#include <iostream>


template<class T, class container = std::vector<T>>
class Queue {
public:
    using value_type = typename container::value_type;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = typename container::size_type;

    Queue(size_type cap);
    Queue(const Queue& other);
    Queue(Queue&& other);
    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other);
    ~Queue() = default;

    void push(const value_type& value);
    void pop();
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    size_type size() const;
    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
private:
    container obj;
};


#include "queue.hpp"