#ifndef SLLNODE_H
#define SLLNODE_H

class SLLNode {
public:
    SLLNode(int d = 0, SLLNode *n = nullptr)
    {
        data = d;
        next = n;
    }

    int data;
    SLLNode *next; // ptr to the next node
    SLLNode *prev;
};

#endif