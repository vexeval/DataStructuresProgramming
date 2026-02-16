#include "Stack.hpp"
#include <iostream>
#include <stdexcept>

template <typename T, int size>
StackArray::Stack<T, size>::Stack() : top_idx(-1) { }

template <typename T, int size>
void StackArray::Stack<T, size>::push(const T& val)
{
    if (full()) {
        throw std::out_of_range("Full stack");
    }
    else {
        data[++top_idx] = val;
    }

}

template <typename T, int size>
bool StackArray::Stack<T, size>::empty() const {
    return top_idx == -1;    
}

template <typename T, int size>
bool StackArray::Stack<T, size>::full() const {
    return top_idx == size - 1;
}

template <typename T, int size>
void StackArray::Stack<T, size>::print() const
{
    int i = top_idx;
    while (i >= 0)
    {
        std::cout << data[i] << std::endl;
        i--;
    }
}

template <typename T, int size>
T StackArray::Stack<T, size>::pop()
{
    if (empty()) {
        throw std::out_of_range("Empty stack");
    }
    else {
        return data[top_idx--];
    }
}

template <typename T, int size>
const T& StackArray::Stack<T, size>::top() const
{
    if (empty()) {
        throw std::out_of_range("Empty stack");
    }
    else {
        return data[top_idx];
    }
}

// StackList Namespace

template <typename T>
StackList::Stack<T>::Stack() : top_node(nullptr) {}

template <typename T>
StackList::Stack<T>::~Stack()
{
    while (!empty())
        pop();
}

template <typename T>
void StackList::Stack<T>::push(const T& val)
{
    if (empty()) top_node = new Node<T>(val, nullptr);

    Node<T> cur = new Node<T>(val, top_node->next);

    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = new Node<T>(val, nullptr);
    
}

template <typename T>
bool StackList::Stack<T>::empty() const
{
    return top_node == nullptr;
}

template <typename T>
void StackList::Stack<T>::print() const
{
    Node<T>* cur = top_node;

    while (cur->next != nullptr)
    {
        std::cout << cur->data;
        cur = cur->next;
        if (cur->next != nullptr) std::cout << " -> ";
    }
    std::cout << std::endl;
}

template <typename T>
T StackList::Stack<T>::pop()
{
    if (empty()) {
        throw std::out_of_range("Empty stack");
    }
    else {
        Node<T>* old_head = top_node;
        T popped_val = old_head->data;
        top_node = top_node->next;
        delete old_head;
        return popped_val;
    }
}

template <typename T>
const T& StackList::Stack<T>::top() const
{
    return top_node->data;
}