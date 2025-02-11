#include "vector.h"
#include <iostream>

Vector::Vector(size_type size) : size_{size}, cap_{size} {
    arr = new value_type[cap_];
}


Vector::Vector(size_type size, const_reference val) : size_{size}, cap_{size} {
    arr = new value_type[cap_];
    for (size_type i = 0; i < size_; ++i) {
        arr[i] = val;
    }
}

Vector::Vector(const Vector& obj) : size_{obj.size_}, cap_{obj.cap_} {
    arr = new value_type[cap_];
    for (size_type i = 0; i < size_; ++i) {
        arr[i] = obj.arr[i];
    }
}

Vector::Vector(Vector&&  obj) noexcept : size_{obj.size_}, cap_{obj.cap_}, arr{obj.arr} {
    obj.size_ = 0;
    obj.cap_  = 0;
    obj.arr = nullptr;
}

Vector::Vector(std::initializer_list<value_type> init) : size_{init.size()}, cap_{init.size()} {
    arr = new value_type[cap_];
    size_type i = 0;
    for (const value_type item : init) {
        arr[i++] = item;
    }
}

Vector::~Vector() {
    delete[] arr;
}

void Vector::reserve(size_type cap) {
    if (cap <= cap_) {
        throw std::out_of_range("cap == cap");
    }

    value_type *tmp = new value_type[cap];
    for (size_type i = 0; i < size_; ++i) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    cap_ = cap;
}

void Vector::resize(size_type size, const_reference val) {
    if (size == size_) {
        return;
    }

    reserve(size);
    for (size_type i = size_; i < size; ++i) {
        arr[i] = val;
    }
    size_ = size;
}

void Vector::assign(size_type count, const_reference val) {
    if (count != size_) {
        resize(count);
    }
    size_ = count;
    for (size_type i = 0; i < size_; ++i) {
        arr[i] = val;
    }
}


void Vector::push_back(const_reference val) {
    if (size_ == cap_) {
        reserve(cap_ * 2);
    }

    arr[size_ + 1] = val;
}

void Vector::pop_back() {
    if (size_ > 0) {
        --size_;
    }
}

refernce Vector::front() {
    return arr[0];
}

const_reference Vector::front() const {
    return arr[0];
}

refernce Vector::back() {
    return arr[size_ - 1];
}

const_reference Vector::back() const {
    return arr[size_ - 1];
}

refernce Vector::at(size_type index) {
    if (index >= size_) {
        throw std::out_of_range("out of range");
    }
    return arr[index];
}

const_reference Vector::at(size_type index) const {
    if (index >= size_) {
        throw std::out_of_range("out of range");
    }
    return arr[index];
}

refernce Vector::operator[](size_type index) {
    return arr[index];
}

const_reference Vector::operator[](size_type index) const {
    return arr[index];
}


bool Vector::empty() const {
    return (size_ == 0) ? false : true; 
}

void Vector::clear() {
    size_ = 0;
}

size_type Vector::insert(size_type index, const_reference val) {
    if (size_ == cap_) {
        reserve(cap_ * 2);
    }
    for (size_type i = size_; i > index; --i) {
        arr[i] = arr[i - 1];
    }   
    arr[index] = val;
    ++size_;
    return index;
}

size_type Vector::insert(size_type index, std::initializer_list<value_type> init) {
    if (size_ == cap_) {
        reserve(cap_ * 2);
    }
    if (size_ + init.size() > cap_) {
        reserve(size_ + init.size());
    }

    for (size_type i = size_ + init.size() - 1; i >= index + init.size(); --i) {
        arr[i] = arr[i - init.size()];
    }
    size_type i = 0;
    for (value_type item : init) {
        arr[i + index] = item;
        ++i;
    }
    size_ += init.size();
    return index;
}

size_type Vector::erase(size_type index) {
    if (index == size_ - 1) {
        pop_back();
        return size_ - 1;
    }
    if (index > size_) {
        throw std::out_of_range("out of range");
    }
    value_type *tmp = new value_type[size_ - 1];
    for (size_type i = 0, j = 0; i < size_; ++i) {
        if (index == i) {
            ++i;
        }
        tmp[j++] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    --size_;
    return index;
}

size_type Vector::erase(size_type first, size_type last) {
    value_type *tmp = new value_type[size_ - (last - first + 1)];
    for (size_type i = 0, j = 0; i < size_; ++i) {
        if (i >= first && i < last) {
            ++i;
        }
        tmp[j++] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    size_ -= (last - first + 1);
    return first;
}

size_type Vector::size() const {
    return size_;
}