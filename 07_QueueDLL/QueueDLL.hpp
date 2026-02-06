#ifndef QUEUEDLL_H
#define QUEUEDLL_H
#include "DLList.hpp"

template <typename T>
class QueueDLL {
public:
    int size() const;
    int length() const;
    bool empty() const;
    void print() const;
    void clear();

    void enqueue(const T& val);
    // Throws std::out_of_range exception
    const T dequeue();
    const T& front() const; // return the first element in the queue

private:
    DLList<T> data;
};

#endif