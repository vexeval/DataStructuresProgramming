#ifndef BST_HPP
#define BST_HPP
#include "BTNode.hpp"

template <typename T>
class BST {
public:
    BST();

    bool empty() const;
    void insert(const T& val);
    BTNode<T>* insert_recursive(const T& val);
    
    // traversal
    void inorder() const;
    void preorder() const;
    void postorder() const;

    void display() const;
    int getFurthestDepth();

    bool isFullTree() const;
    BTNode<T>* search(const T& val) const;

private:
    BTNode<T>* root;

    void inorder(BTNode<T>* node) const;

    BTNode<T>* insert_recursive(BTNode<T>* node, const T& val);

    void display(BTNode<T>* node, int space) const;

    int getFurthestDepth(BTNode<T>* node);

    bool isFullTree(BTNode<T>* node) const;

};

#endif