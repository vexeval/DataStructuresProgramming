#ifndef QUEUEDLL_H
#define QUEUEDLL_H
#include "DLList.hpp"

template <typename T>
class QueueDLL {
public:
    QueueDLL();
    int length() const;
    bool empty() const;
    bool full() const;
    void print() const;
    void clear();

    void enqueue(const T& val);
    // Throws std::out_of_range exception
    const T& dequeue();
    const T& front(); // return the first element in the queue

private:
    DLList<T>* data;
};

#endif