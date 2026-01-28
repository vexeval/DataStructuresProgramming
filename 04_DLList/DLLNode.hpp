#ifndef DLLNODE_H
#define DLLNODE_H

template <typename T>
class DLLNode {
    // T() - default template value
public:
    DLLNode(const T& d = T(), DLLNode<T> *p = nullptr, DLLNode<T> *n = nullptr)
    {
        data = d;
        prev = p;
        next = n;
    }

    T data;
    DLLNode<T> *next; // ptr to the next node
    DLLNode<T> *prev;
};

#endif