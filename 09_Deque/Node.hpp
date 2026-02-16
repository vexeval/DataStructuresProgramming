#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
public:
    Node(const T& d = T(), Node<T>* p = nullptr, Node<T>* n = nullptr) {
        data = d;
        prev = p;
        next = n;
    }

    T data;
    Node<T>* next; // pointer to the next node
    Node<T>* prev; // pointer to the previous node
};

#endif