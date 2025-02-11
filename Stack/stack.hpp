#pragma once 
#include "stack.h"

template<class T, class container>
Stack<T, container>::Stack(size_type size) : obj(size){}

template<class T, class container>
Stack<T, container>::Stack(const Stack& other) : obj(other.obj){}

template<class T, class container>
Stack<T, container>::Stack(Stack&& other) : obj(std::move(other.obj)){}

template<class T, class container>
Stack<T, container>& Stack<T, container>::operator=(const Stack& other) noexcept {
    if (this != &other) {
        obj = other.obj;
    }
    return *this;
}

template<class T, class container>
Stack<T, container>& Stack<T, container>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        obj = std::move(other.obj);
    }
    return *this;
}


template<class T, class container>
void Stack<T, container>::push(const_reference val) {
    obj.push_back(val);
}

template<class T, class container>
void Stack<T, container>::pop() {
    obj.pop_back();
}

template<class T, class container>
typename Stack<T, container>::reference Stack<T, container>::top() {
    return obj.back();
}

template<class T, class container>
typename Stack<T, container>::const_reference Stack<T, container>::top() const {
    return obj.back();
}

template<class T, class container>
typename Stack<T, container>::size_type Stack<T, container>::size() const {
    return obj.size();
}

template<class T, class container>
bool Stack<T, container>::empty() {
    return obj.empty();
}

template<class T, class container>
typename Stack<T, container>::reference Stack<T, container>::operator[](size_type index) {
    return obj[index];
}

template<class T, class container>
typename Stack<T, container>::const_reference Stack<T, container>::operator[](size_type index) const {
    return obj[index];
}