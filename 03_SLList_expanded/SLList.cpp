#include "SLList.hpp"
#include <iostream>

template <typename T>
SLList<T>::SLList()
{
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

template <typename T>
SLList<T>::~SLList()
{
    clear();
}

template <typename T>
SLList<T>::SLList(const SLList<T>& other)
{
    head = nullptr;
    tail = nullptr;
    list_size = 0;

    // iterate through other list and add its values
    SLLNode<T>* cur = other.head;
    while (cur != nullptr)
    {
        push_back(cur->data);
        cur = cur->next;
    }
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other)
{
    if (this != &other)
    {
        clear(); // clean
        // copy
        SLLNode<T>* cur = other.head;
        while (cur != nullptr)
        {
            push_back(cur->data);
            cur = cur->next;
        }
    }
    
    return *this;
}

template <typename T>
unsigned SLList<T>::size() const
{
    return list_size;
}

template <typename T>
bool SLList<T>::empty() const
{
    return (size() == 0);
}

template <typename T>
void SLList<T>::push_front(T val)
{
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;
    head = new SLLNode<T>(val, head);
    list_size++;
    if (size() == 1) tail = head;
}

template <typename T>
void SLList<T>::print() const
{
    std::cout << "{ ";
    SLLNode<T>* cur = head;
    while (cur)
    {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next; // next node
    }
    std::cout << " }\n";
}

template <typename T>
void SLList<T>::push_back(const T& val)
{
    if (empty())
    {
        push_front(val);
        return;
    }
    tail->next = new SLLNode<T>(val); // add node to the end
    tail = tail->next; // move tail

    list_size++;
}

template <typename T>
void SLList<T>::pop_front()
{
    if (empty()) return;

    SLLNode<T> *prev_head = head;
    head = head->next;
    delete prev_head;
    list_size--;
    if (empty()) tail = head;
}

template <typename T>
void SLList<T>::pop_back()
{
    if (empty()) return;

    // only one node in list
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        list_size = 0;
    }
    else // more than one node
    {
        SLLNode<T>* cur = head;
        // move till cur is second to last node
        while (cur->next != tail)
        {
            cur = cur->next;
        }

        delete tail;
        tail = cur;
        tail->next = nullptr;
        list_size--;
    }
}

template <typename T>
void SLList<T>::clear()
{
    while (!empty())
        pop_front();
}

template <typename T>
void SLList<T>::insert(unsigned pos, const T& value, unsigned n)
{
    if (pos > list_size || n == 0)
        return;
    
    // insert at beginning
    if (pos == 0)
    {
        for (int i = 0; i < n; i++)
        {
            push_front(value);
        }
        return;
    }

    // inserting at middle or end. find point at pos - 1
    SLLNode<T>* prev = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = prev->next;
    }

    // insert n nodes after prev
    for (int i = 0; i < n; i++)
    {
        SLLNode<T>* newNode = new SLLNode<T>(value, prev->next);
        prev->next = newNode;
        if (prev == tail) // update if inserting at end
            tail = newNode;

        // advance prev
        prev = newNode;
        list_size++;
    }
}

template<typename T>
void SLList<T>::erase(unsigned pos)
{
    if (pos >= list_size)
        return;
    
    // remove first el
    if (pos == 0)
    {
        pop_front();
        return;
    }

    // remove last el
    if (pos == list_size - 1)
    {
        pop_back();
        return;
    }

    // removing from middle
    SLLNode<T>* prev = head;
    // node before the one to be deleted
    for (int i = 0; i < pos - 1; i++)
    {
        prev = prev->next;
    }

    SLLNode<T>* toDelete = prev->next;
    prev->next = toDelete->next;

    delete toDelete;
    list_size--;
}

template <typename T>
void SLList<T>::remove(const T& value)
{
    while (!empty() && head->data == value)
    {
        pop_front();
    }

    if (empty()) return;

    // handle rest of list
    SLLNode<T>* cur = head;

    // look at next node
    while (cur->next != nullptr)
    {
        if (cur->next->data == value)
        {
            SLLNode<T>* toDelete = cur->next;
            cur->next = toDelete->next;

            if (toDelete == tail)
                tail = cur;
            
            delete toDelete;
            list_size--;
        }
        else
        {
            // only move if nothing was deleted
            cur = cur->next;
        }
    }
}

template<typename T>
void SLList<T>::rotate_right(unsigned k)
{
    if (list_size < 2 || k == 0)
        return;
    
    int moves = k % list_size; // only need to rotate k%size times if k > size
    if (moves == 0)
        return;
    
    tail->next = head;

    // find new tail. rotating by moves means new tail is at (size-moves-1). from head, number of steps is (list_size - moves).
    SLLNode<T>* newTail = head;
    for (int i = 1; i < list_size - moves; i++)
    {
        newTail = newTail->next;
    }

    head = newTail->next;
    tail = newTail;

    // break circle
    tail->next = nullptr;
}