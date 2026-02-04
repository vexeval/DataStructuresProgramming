#ifndef DLList_H
#define DLList_H
#include "DLLNode.hpp"

template <typename T>
class DLList {
public:
    DLList(); // no-arg constructor
    // DLList(const DLList& other);  // copy constructor
    // DLList& operator=(const DLList& other); // assignment operator // TODO
    // ~DLList(); // destructor

    // unsigned size() const;
    bool empty() const;
    void push_front(const T& val); // Insert the new node at the beginning
    void push_back(const T& val); // Insert the new node at the end
    void pop_front(); // Remove the first element node
    void print_backwards() const;
    void pop_back(); // Remove the last element node
    // void insert(int position, int value);
    // void erase(int position);
    // void clear(); // Clear the list
    void print() const;
private:
    DLLNode<T>* head; // ptr to first node
    DLLNode<T>* tail; // ptr to last node
    unsigned list_size;

};

#endif