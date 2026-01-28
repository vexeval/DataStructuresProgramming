#ifndef SLList_H
#define SLList_H
#include "SLLNode.hpp"

template <typename T>
class SLList {
public:
    SLList(); // no-arg constructor
    SLList(const SLList<T>& other);  // copy constructor
    SLList& operator=(const SLList<T>& other); // assignment operator
    ~SLList(); // destructor

    unsigned size() const;
    bool empty() const;
    void push_front(T val); // Insert the new node at the beginning
    void push_back(const T& val); // Insert the new node at the end
    void pop_front(); // Remove the first element node
    void pop_back(); // Remove the last element node
    void insert(int position, T& value); // Insert value at position
    void erase(int position);
    void clear(); // Clear the list
    void print() const;
private:
    SLLNode<T>* head; // ptr to first node
    SLLNode<T>* tail; // ptr to last node
    unsigned list_size;

};

#endif