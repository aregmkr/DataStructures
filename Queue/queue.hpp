#pragma once
#include "queue.h"

template<class T, class container>
Queue<T, container>::Queue(size_type cap) : obj(cap){}

template<class T, class container>
typename Queue<T, container>::reference Queue<T, container>::front() {
    return obj.front();
}

template<class T, class container>
typename Queue<T, container>::const_reference Queue<T, container>::front() const {
    return obj.front();
}

template<class T, class container>
typename Queue<T, container>::reference Queue<T, container>::back() {
    return obj.back();
}

template<class T, class container>
typename Queue<T, container>::const_reference Queue<T, container>::back() const {
    return obj.back();
}

template<class T, class container>
void Queue<T, container>::push(const value_type& value) {
    obj.push_back(value);
}

template<class T, class container>
void Queue<T, container>::pop() {
    if (!obj.empty()) {
        obj.pop_back();
    }
    throw std::underflow_error("empty");
}

template<class T, class contianer>
Queue<T, contianer>::Queue(const Queue& other) : obj(other.obj) {}

template<class T, class container>
Queue<T, container>::Queue(Queue&& other) : obj(std::move(other.obj)) {}

template<class T, class contianer>
Queue<T, contianer>& Queue<T, contianer>::operator=(const Queue& other) {
    if (this != &other) {
        obj = other.obj;
    }
    return *this;
}

template<class T, class container>
Queue<T, container>& Queue<T, container>::operator=(Queue&& other) {
    if (this != &other) {
        obj = std::move(other.obj);
    }
    return *this;
}

template<class T, class container>
typename Queue<T, container>::size_type Queue<T, container>::size() const {
    return obj.size();
}

template<class T, class container>
typename Queue<T, container>::reference Queue<T, container>::operator[](size_type index) {
    return obj[index];
}

template<class T, class container>
typename Queue<T, container>::const_reference Queue<T, container>::operator[](size_type index) const {
    return obj[index];
}