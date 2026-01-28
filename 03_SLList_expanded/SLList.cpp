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
void SLList<T>::insert(int position, T& value)
{
    // TODO
    // do not insert if pos > list size
    // use push_front to insert at the beginning
    // find the node before the specified pos
    // insert the new node after the found node

}

template <typename T>
void SLList<T>::erase(int position)
{
    // TODO
    // Do not erase if pos >= list size
    // use pop_front
    // find the node before the specified position
    // update the next pointer of the found node with the next value of the next node
    // release the memory

}