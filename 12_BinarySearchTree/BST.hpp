#ifndef BST_HPP
#define BST_HPP
#include "BTNode.hpp"
#include <string>

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
    BTNode<T>* getMinNode(BTNode<T>* source) const;
    BTNode<T>* searchParent(const T& val) const;
    void deleteNode(const T& val);
    void print() const;
    
private:
    BTNode<T>* root;
    
    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithTwoChildren(BTNode<T>* node);
    void inorder(BTNode<T>* node) const;
    void display(BTNode<T>* node, int space) const;
    int getFurthestDepth(BTNode<T>* node);
    bool isFullTree(BTNode<T>* node) const;
    BTNode<T>* insert_recursive(BTNode<T>* node, const T& val);
    void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;
};

#endif