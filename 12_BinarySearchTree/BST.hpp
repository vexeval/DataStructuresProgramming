#ifndef BST_HPP
#define BST_HPP
#include "BTNode.hpp"

template <typename T>
class BST {
public:
    BST();

    bool empty() const;
    void insert(const T& val);

    // traversal
    void inorder() const;
    void display() const;

    int getFurthestDepth();

    private:
    BTNode<T>* root;
    void inorder(BTNode<T>* node) const;
    void display(BTNode<T>* node, int space) const;
    int getFurthestDepth(BTNode<T>* node);
};

#endif