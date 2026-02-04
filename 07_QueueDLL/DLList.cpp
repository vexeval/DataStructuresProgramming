#include "DLList.hpp"
#include <iostream>

template <typename T>
DLList<T>::DLList()
{
    head = new DLLNode<T>; // sentinel head node
    tail = new DLLNode<T>; // sentinel tail node
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
void DLList<T>::push_front(const T& val)
{
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;
    
    list_size++;
}

template <typename T>
void DLList<T>::print() const
{
    DLLNode<T>* cur = head->next;
    while (cur != tail)
    {
        std::cout << cur->data;
        if (cur->next != tail) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DLList<T>::pop_back()
{
    if (!empty())
    {
        DLLNode<T>* to_del = tail->prev;
        tail->prev = to_del->prev;
        tail->prev->next = tail;

        list_size--;
        delete to_del;
    }
}

template <typename T>
bool DLList<T>::empty() const
{
    return (list_size == 0);
}

template <typename T>
void DLList<T>::pop_front()
{
    if (!empty())
    {
        // real first
        DLLNode<T>* to_del = head->next;

        // link head to node after del
        head->next = to_del->next;

        // link node after the one being deleted back to head
        to_del->next->prev = head;

        delete to_del;
        list_size--;
    }
}

template <typename T>
void DLList<T>::print_backwards() const
{
    // start at real last node
    DLLNode<T>* cur = tail->prev;

    // stop upon hitting sentinel head
    while (cur != head)
    {
        std::cout << cur->data;

        // only print arrow if prev node != sentinel head
        if (cur->prev != head)
        {
            std::cout << " -> ";
        }
        cur = cur->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void DLList<T>::push_back(const T& val)
{
    DLLNode<T>* new_node = new DLLNode<T>(val, tail->prev, tail);
    tail->prev->next = new_node;
    tail->prev = new_node;
    
    list_size++;
}