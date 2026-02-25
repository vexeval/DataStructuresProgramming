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
    
    
    // inorder(node->left, height + 1);
    // std::cout << std::string(height, ' ') << node->data << ' ';
    
    // std::string indent = "";
    // for (int i = 1; i < height; i++) {
    //     indent += "    ";
    // }
        
    // std::cout << '\n' << indent << node->data;
    // inorder(node->right, height + 1);
}
    
template <typename T>
void BST<T>::display() const
{
    std::cout << "Display:\n";
    display(root, 0);
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
    std::cout << node->data << '\n';

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

