#include "forwardList.h"
#include <iostream>
#include <vector>

template<class T>
ForwardList<T>::ForwardList() : before{Node(T())} {
    before.next = nullptr;
}

template<class T>
ForwardList<T>::ForwardList(const_reference val) : ForwardList() {
    push_front(val);
}


template<class T>
ForwardList<T>::ForwardList(const ForwardList& other) : before{Node()} {
    Node *it = before;
    Node *other_it = other.before;
    while(other_it) {
        it->next = new Node(other_it->value);
        it = it->next;
        other_it = other_it->next;
    }
}


template<class T>
ForwardList<T>::~ForwardList() {
    clear();
}

template<class T>
ForwardList<T>::ForwardList(std::initializer_list<T> init) {
    Node *it = &before;
    for (auto i : init) {
        it->next = new Node(i);
        it = it->next;
    }
}

template<class T>
ForwardList<T>::ForwardList(ForwardList&& other) : before{Node()} {
    Node *it = before;
    it->next = other.before->next;
    other.before->next = nullptr;
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    Node *it = other.before->next;
    Node *tmp = before;

    while (it) {
        Node *new_tmp = new Node(it->value);
        tmp->next = new_tmp;
        tmp = new_tmp;
        it = it->next;
    }
    return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList&& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    before->next = other.before->next;
    other.before->next = nullptr;
    return *this;
}


template<class T>
typename ForwardList<T>::iterator ForwardList<T>::find(iterator head, size_type idx) {
    Node *it = head.ptr;
    while(it && idx != 0) {
        it = it->next;
        --idx;
    }
    return iterator(it);
}

template<class T>
typename ForwardList<T>::const_iterator ForwardList<T>::find(iterator head, size_type idx) const {
    Node *it = head.ptr;
    while(it && idx != 0) {
        it = it->next;
        --idx;
    }
    return iterator(it);
}

template<class T>
bool ForwardList<T>::empty() {
    return before->next == nullptr;
}

template<class T>
typename ForwardList<T>::reference ForwardList<T>::at(size_type idx) {
    Node *it = find(before, idx);
    return it->value;
}

template<class T>
typename ForwardList<T>::const_reference ForwardList<T>::at(size_type idx) const {
    Node *it = find(before, idx);
    return it->value;
} 

template<class T>
typename ForwardList<T>::reference ForwardList<T>::front() {
    if (before) {
        return before->next;
    }
}

template<class T>
typename ForwardList<T>::const_reference ForwardList<T>::front() const {
    if (before) {
        return before->next;
    }
}

template<class T>
typename ForwardList<T>::size_type ForwardList<T>::size() const {
    Node *it = before;
    size_type size = 0;
    while(it) {
        it = it->next;
        ++size;
    }
    return size;
}

template<class T>
typename ForwardList<T>::iterator ForwardList<T>::insert_after(iterator pos, const_reference val) {
    if (!pos.getPtr()) {
        return iterator();
    }
    Node *tmp = pos.getPtr()->next;
    pos.getPtr()->next = new Node{val};
    pos.getPtr()->next->next = tmp;
    return iterator(pos.getPtr()->next);
}

template<class T>
typename ForwardList<T>::iterator ForwardList<T>::insert_after(iterator pos, std::initializer_list<T> init) {
    Node *res = nullptr;
    for (int i = 0; i < init.size(); ++i) {
        Node *tmp = new Node(init[i]);
        tmp->next = pos.ptr->next;
        pos.ptr->next = tmp;
        res = tmp;
    }
    return iterator(res);
}

template<class T>
typename ForwardList<T>::iterator ForwardList<T>::erase_after(iterator pos) {
    Node *tmp = pos.ptr->next;
    pos.ptr->next = tmp->next;
    delete tmp;
    return Iteraotr(pos.ptr->next);
}

template<class T>
typename ForwardList<T>::iterator ForwardList<T>::erase_after(iterator first, iterator last) {
    Node *tmp = first.ptr;
    Node *del = tmp->next;
    while(del && del != last.ptr) {
        Node *z = del;
        del = del->next;
        delete z;
    }
    tmp->next = last.ptr;
    return iterator(last.ptr);
}

template<class T>
void ForwardList<T>::push_front(const_reference val) {
    Node* newNode = new Node(val);
    newNode->next = before.next;
    before.next = newNode;
}

template<class T>
void ForwardList<T>::push_front(T&& val) {
    Node* newNode = new Node(val);
    newNode->next = before.next;
    before.next = newNode;
}

template<class T>
void ForwardList<T>::pop_front() {
    Node *tmp = before->next->next;
    delete before->next;
    before->next = tmp;
}

template<class T>
typename ForwardList<T>::iterator ForwardList<T>::begin() {
    return iterator(before.next);
}

template<class T>
typename ForwardList<T>::const_iterator ForwardList<T>::begin() const{
    return iterator(before.next);
}

template<class T>
typename ForwardList<T>::iterator ForwardList<T>::end() {
    return iterator(nullptr);
}

template<class T>
typename ForwardList<T>::const_iterator ForwardList<T>::end() const {
    return iterator(nullptr);
}

template<class T>
typename ForwardList<T>::const_iterator ForwardList<T>::cbegin() const {
    return iterator(before->next);
}

template<class T>
typename ForwardList<T>::const_iterator ForwardList<T>::cend() const {
    return iterator(nullptr);
}

template<class T>
void ForwardList<T>::splice(iterator pos, ForwardList& obj) {
    Node *it = obj.before->next;
    Node *tmp = obj.before->next;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = pos->next;
    pos.ptr->next = it;
    obj.before = nullptr;
}

template<class T>
void ForwardList<T>::splice(iterator pos, iterator first, iterator last) {
    Node *it = first.ptr->next;
    Node *tmp = first.ptr->next;

    while (it->next != last.ptr) {
        it = it->next;
    }
    it->next = pos->next;
    pos.ptr->next = tmp;
}

template<class T>
void ForwardList<T>::clear() {
    Node *it = before.next;
    while (it) {
        Node *tmp = it->next;
        delete it;
        it = tmp;
    }
    before.next = nullptr;
}

template<class T>
void ForwardList<T>::print() {
    Node *it = before.next;
    while (it != nullptr) {
        std::cout << it->value << " ";
        it = it->next;
    }
}

template<class T>
void ForwardList<T>::resize(size_type size, const_reference val) {
}
