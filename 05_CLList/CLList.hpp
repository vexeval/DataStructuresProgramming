#ifndef CLLIST_H
#define CLLIST_H

template <typename T>
class CLList {
public:
    CLList(); // No-arg constructor
    bool empty() const; // Return true if list is empty
    void push_front(const T& val); // Insert at the beginning
    void push_back(const T& val); // Insert at the end
    void print() const; // Print the list
    void print_backwards() const; // Print the list backwards
    void pop_back(); // Remove the last element (node)
    void pop_front(); // Remove the first element (node)

};

#endif
