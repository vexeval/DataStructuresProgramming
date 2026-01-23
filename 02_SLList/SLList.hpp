#ifndef SLList_H
#define SLList_H
#include "SLLNode.hpp"

class SLList {
public:
    SLList();

    unsigned size() const;
    bool empty() const;
    void push_front(int val); // Insert the new node at the beginning
    void print() const;
    // TODO
    void push_back(int val); 
private:
    SLLNode* head;
    unsigned list_size;

};

#endif