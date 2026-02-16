#include "Deque.hpp"
#include "Node.hpp"

#include <iostream>
#include <stdexcept>

template <typename T>
Deque<T>::Deque() {
    head = new Node<T>;
    tail = new Node<T>; 
    head->next = tail;
    tail->prev = head;
}

template <typename T>
Deque<T>::~Deque() {
    clear();
    delete head;
    delete tail;
}

template <typename T>
void Deque<T>::push_front(const T& val) {
    head->next = new Node<T>(val, head, head->next);
    head->next->next->prev = head->next;
}

template <typename T>
void Deque<T>::push_back(const T& val) {
    // sentinels prevent need for empty check
    Node<T>* new_node = new Node<T>(val, tail->prev, tail);
    tail->prev->next = new_node;
    tail->prev = new_node;
}

template <typename T>
void Deque<T>::print() const {
    Node<T>* cur = head->next;
    while (cur != tail)
    {
        std::cout << cur->data;
        if (cur->next != tail) std::cout << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
T Deque<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }
    else {
        Node<T>* to_del = head->next;
        T r_val = to_del->data;
        head->next = to_del->next; // unlink node
        to_del->next->prev = head;
    
        delete to_del;
        return r_val;
    }
}

template <typename T>
T Deque<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }
    else {
        Node<T>* to_del = tail->prev;
        T r_val = to_del->data;
        tail->prev = to_del->prev; // unlink
        tail->prev->next = tail;

        delete to_del;
        return r_val;
    }
}

template <typename T>
bool Deque<T>::empty() const {
    return size() == 0;
}

template <typename T>
const T& Deque<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Empty deque");
    }
    else {
        return head->next->data;
    }
}

template <typename T>
const T& Deque<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Empty deque");
    }
    else {
        return tail->prev->data;
    }
}

template <typename T>
int Deque<T>::size() const {
    int size = 0;
    Node<T>* cur = head->next;
    while (cur != tail)
    {
        size++;
        cur = cur->next;
    }
    return size;
}

template <typename T>
void Deque<T>::clear() {
    while (!empty())
        pop_front();
}