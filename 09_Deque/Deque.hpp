#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "Node.hpp"

template <typename T>
class Deque {
public:
    Deque();
    ~Deque();

    void    push_front(const T& val);
    void    push_back(const T& val);
    void    print() const;

    T       pop_front();
    T       pop_back();

    bool    empty() const;

    const T& front() const;
    const T& back() const;

    int     size() const;
    void    clear();


private:
    Node<T>* head;
    Node<T>* tail;
};

#endif