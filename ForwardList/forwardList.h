#ifndef __FORWARDLIST_H__
#define __FORWARDLIST_H__
#include <vector>
#include <iostream>

template<class T>
class ForwardList {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = size_t; 

private:
    struct Node {
        T value;
        Node *next;
        Node() : value{}, next{nullptr} {}
        Node(const T& value) : value{value}, next{nullptr} {}
    };

public:
    class const_iterator {
    protected:
        Node *ptr;
    public:
        using iterator_cateogry = std::forward_iterator_tag;

        explicit const_iterator(Node *ptr) : ptr{ptr} {}
        const T& operator*() const {
            return ptr->value;
        }
        
        bool operator==(const const_iterator& other) {
            return ptr == other.ptr;
        }

        const_iterator& operator++() {
            if (ptr) {
                ptr = ptr->next;
            }
            return *this;
        }

        Node* getPtr() const {
            return this->ptr;
        }

    };

    class iterator : public const_iterator {
    public:
        using iterator_cateogry = std::forward_iterator_tag;

        explicit iterator(Node *ptr = nullptr) : const_iterator(ptr) {}
        iterator(const iterator& other) : const_iterator(other.ptr) {}
        iterator(iterator&& other) : const_iterator(other.ptr) {
            other.ptr = nullptr;
        }
        
        iterator& operator=(const iterator& other) {
            if (this != &other) {
                this->ptr = other.ptr;
            }
            return *this;
        }

        iterator& operator=(iterator&& other) {
            if (this != &other) {
                this->ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }

        const T& operator*() const {
            return this->ptr->value;
        }
        Node *getPtr() const {return this->ptr;}
    };

    ForwardList();
    explicit ForwardList(const_reference val);
    ForwardList(const ForwardList& other);
    ForwardList(ForwardList&& other);
    ForwardList(std::initializer_list<T> init);
    ForwardList& operator=(const ForwardList& other);
    ForwardList& operator=(ForwardList&& other);
    ~ForwardList();

    bool empty();
    iterator find(iterator head, size_type idx);
    const_iterator find(iterator head, size_type idx) const;
    reference at(size_type idx);
    const_reference at(size_type idx) const;
    reference front();
    const_reference front() const;
    size_type size() const;
    iterator insert_after(iterator pos, const_reference val);
    iterator insert_after(iterator pos, std::initializer_list<T> init);
    iterator erase_after(iterator pos);
    iterator erase_after(iterator first, iterator last);
    void splice(iterator pos, ForwardList& obj);
    void splice(iterator pos, iterator first, iterator last);
    void push_front(const_reference val);
    void push_front(T&& val);
    void pop_front();
    void resize(size_type size, const_reference val = value_type());
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    void clear();
    void print();
private:
    Node before;
};

#include "forwardList.hpp"
#endif // __FORWARDLIST_H__