#ifndef SLList_H
#define SLList_H
#include "SLLNode.hpp"

class SLList {
public:
    SLList(); // no-arg constructor
    SLList(const SLList& other);  // copy constructor
    SLList& operator=(const SLList& other); // assignment operator // TODO
    ~SLList(); // destructor

    unsigned size() const;
    bool empty() const;
    void push_front(int val); // Insert the new node at the beginning
    void push_back(int val); // Insert the new node at the end
    void pop_front(); // Remove the first element node
    void pop_back(); // Remove the last element node
    void clear(); // Clear the list
    void print() const;
private:
    SLLNode* head; // ptr to first node
    SLLNode* tail; // ptr to last node
    unsigned list_size;

};

#endif