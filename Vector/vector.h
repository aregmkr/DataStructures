
#pragma once
#include <iostream>
using value_type = int;
using refernce = value_type&;
using const_reference = const value_type&;
using pointer = value_type*;
using const_pointer = const value_type*;
using size_type = size_t;

class Vector {
public:
    Vector(size_type size);
    Vector(size_type size, const_reference val);
    Vector(const Vector& obj);
    Vector(Vector&& obj) noexcept;
    Vector(std::initializer_list<value_type> init);
    ~Vector();

    void assign(size_type count, const_reference val);
    void push_back(const_reference val);
    void pop_back();

    refernce front();
    const_reference front() const;
    refernce back();
    const_reference back() const;
    refernce at(size_type index);
    const_reference at(size_type index) const;
    refernce operator[](size_type index);
    const_reference operator[](size_type index) const;
    

    size_type insert(size_type index, const_reference val);
    size_type insert(size_type index, std::initializer_list<value_type> init);
    size_type erase(size_type index);
    size_type erase(size_type first, size_type last);

    void reserve(size_type cap);
    void resize(size_type size, const_reference val = value_type());
    bool empty() const;
    void clear();
    size_type size() const;
private:
    size_type size_;
    size_type cap_;
    value_type *arr;
};
