#include "BST.hpp"
#include <iostream>
#include <string>

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val)
{
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }

    // iterative approach
    BTNode<T>* cur = root;
    BTNode<T>* prev = root;
    while (cur) {
        prev = cur;
        if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    if (prev->data > val) {
        prev->left = new BTNode<T>(val);
    }
    else {
        prev->right = new BTNode<T>(val);
    }
}

template <typename T>
BTNode<T>* BST<T>::insert_recursive(const T& val) {
    root = insert_recursive(root, val);
    return root;
}

template <typename T>
BTNode<T>* BST<T>::insert_recursive(BTNode<T>* node, const T& val)
{
    if (!node) {
        return new BTNode<T>(val);
    }
    
    if (val > node->data) {
        node->right = insert_recursive(node->right, val);
        return node;
    }
    else {
        node->left = insert_recursive(node->left, val);
        return node;
    }
}

template <typename T>
void BST<T>::inorder() const
{
    std::cout << "Inorder: [";
    inorder(root);
    std::cout << " ]\n";
}

template <typename T>
void BST<T>::inorder(BTNode<T>* node) const
{
    if (!node)
    return;
    
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}
    
template <typename T>
void BST<T>::display() const
{
    std::cout << "Display:\n";
    display(root, 0);
    std::cout << '\n';
}

template <typename T>
void BST<T>::display(BTNode<T>* node, int space) const
{
    if (!node) return;

    int count = 5;
    space += count;

    display(node->right, space);

    std::cout << '\n';
    for (int i = count; i < space; i++) std::cout << ' ';
    std::cout << node->data;

    display(node->left, space);
}

template <typename T>
int BST<T>::getFurthestDepth()
{
    return getFurthestDepth(root);
}

template <typename T>
int BST<T>::getFurthestDepth(BTNode<T>* node)
{
    if (!node) return 0;
    
    int lDepth = getFurthestDepth(node->left);
    int rDepth = getFurthestDepth(node->right);
    
    return std::max(lDepth, rDepth) + 1;
}

template <typename T>
bool BST<T>::isFullTree() const
{
    return isFullTree(root);
}

template <typename T>
bool BST<T>::isFullTree(BTNode<T>* node) const
{
    if (!node) return true;
    if (node->hasOneChild()) return false;
    return isFullTree(node->left) && isFullTree(node->right);
}

template <typename T>
BTNode<T>* BST<T>::search(const T& val) const
{
    BTNode<T>* cur = root;
    while (cur) {
        if (cur->data == val) { // found the value
            return cur;
        }
        else if (cur->data > val) { // value is less than cur
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return nullptr;
}