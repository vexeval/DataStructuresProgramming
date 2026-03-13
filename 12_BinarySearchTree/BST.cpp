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

    // if leaf, it's full
    if (!node->hasOneChild() && !node->right) return true;

    // has both children
    if (node->left && node->right) {
        return isFullTree(node->left) && isFullTree(node->right);
    }

    // only one child, so not full tree
    return false;
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

template <typename T>
BTNode<T>* BST<T>::getMinNode(BTNode<T>* source) const
{
    if (!source) return nullptr;
    BTNode<T>* node = source;
    while (node->left != nullptr)
        node = node->left;
    
    return node;
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const
{
    if (!root || root->data == val)
        return nullptr;
    
    BTNode<T>* cur = root;
    while (cur) {
        if ((cur->left && cur->left->data == val) || (cur->right && cur->right->data == val)) {
            return cur;
        }

        // move down tree
        if (cur->data > val) cur = cur->left;
        else cur = cur->right;
    }

    return nullptr;
}

template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent)
{
    BTNode<T>* gc = (child->left != nullptr) ? child->left : child->right;

    if (child == root)
    {
        root = nullptr;
        // root = gc;
        // delete child;
    }
    // else {
    //  if (parent->left == child) parent->left = gc;
    // else parent->right = gc;
    // }
    // delete child;

    if (parent->left == child)
    {
        delete child;
        parent->left = nullptr;
    }
    
    if (parent->right == child)
    {
        delete child;
        parent->right = nullptr;
    }

}

template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent)
{
    if (child == root) {
        BTNode<T>* to_delete = root;
        root = (root->left) ? root->left : root->right;
        delete to_delete;
        return;
    }
    BTNode<T>* grand_kid = (child->right) ? child->right : child->left;
    if (parent->right == child) {
        parent->right = grand_kid;
    }
    if (parent->left == child) {
        parent->left = grand_kid;
    }
    
    delete child;
}

template <typename T>
void BST<T>::deleteNode(const T& val)
{
    BTNode<T>* node = search(val);

    if (!node) {
        std::cout << "Delete: No value in BST\n";
        return;
    }
    BTNode<T>* parent = searchParent(val);

    if (node->isLeaf()) {
        deleteLeaf(node, parent);
    }
    else if (node->hasOneChild()) {
        deleteNodeWithOneChild(node, parent);
    }
    else { // node has 2 children
        deleteNodeWithTwoChildren(node);
    }
}

template <typename T>
void BST<T>::deleteNodeWithTwoChildren(BTNode<T>* node)
{
    BTNode<T>* min_right_node = getMinNode(node->right);
    T min_val = min_right_node->data;

    BTNode<T>* parent = searchParent(min_val);

    if (min_right_node->isLeaf()) {
        deleteLeaf(min_right_node, parent);
    }
    else if (min_right_node->hasOneChild()) {
        deleteNodeWithOneChild(min_right_node, parent);
    }
    node->data = min_val;
}

template <typename T>
void BST<T>::print() const
{
    std::cout << "====================\n";
    print("", root, false);
    std::cout << "====================\n";
}

template <typename T>
void BST<T>::print(const std::string& prefix, BTNode<T>* node, bool isRight) const
{
    if (!node) return;
    std::cout << prefix;
    if (node != root) {
        std::cout << (isRight ? "R----" : "L----");
    } else {
        std::cout << "-----";
    }
    
    // print the value of the node
    std::cout << '[' << node->data << ", " << getHeight(node) << ", " << getBalance(node) << ']' << std::endl;
    
    // go to the next level of the tree
    print(prefix + "     ", node->right, true);
    print(prefix + "     ", node->left, false);
}

template <typename T>
int BST<T>::getHeight(const BTNode<T>* node) const
{
    if (!node) {
        return 0;
    }
    
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);
    
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

template <typename T>
int BST<T>::getBalance(const BTNode<T>* node) const
{
    if (!node) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void BST<T>::rotateRight(BTNode<T>* & node)
{
    if (!node || !node->left) {
        return;
    }
    BTNode<T>* left_child = node->left;
    node->left = left_child->right;
    left_child->right = node;
    node = left_child;
}

template <typename T>
void BST<T>::rotateRightAt(const T& val)
{
    if (!root) return;

    if (root->data == val) {
        rotateRight(root);
        return;
    }

    // find parent so actual ptr variable can be passed by reference
    BTNode<T>* parent = searchParent(val);
    if (!parent) return;

    if (parent->left && parent->left->data == val) {
        rotateRight(parent->left);
    }
    else if (parent->right && parent->right->data == val) {
        rotateRight(parent->right);
    }

}

template <typename T>
BTNode<T>*& BST<T>::searchRef(const T& val) {
    return searchRef(val, root);
}

template <typename T>
BTNode<T>*& BST<T>::searchRef(const T& val, BTNode<T>*& node) {
    if (!node || node->data == val) {
        return node;
    }
    else if (node->data > val) {
        return searchRef(val, node->left);
    }
    else {
        return searchRef(val, node->right);
    }
}

template <typename T>
void BST<T>::rotateRightRef(BTNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    BTNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    
    node = left_kid;
}

template <typename T>
void BST<T>::rotateLeftRef(BTNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    BTNode<T>* right_kid = node->right;
    node->right = right_kid->left;
    right_kid->left = node;
    
    node = right_kid;
}


template <typename T>
void BST<T>::rotateLeftDoubleRef(BTNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    rotateRightRef(node->right);
    rotateLeftRef(node);
}

template <typename T>
void BST<T>::rotateRightDoubleRef(BTNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    rotateLeftRef(node->left);
    rotateRightRef(node);
}


template <typename T>
void BST<T>::balance() {
    balance(root);
}

template <typename T>
void BST<T>::balance(BTNode<T>*& node) {
    if (!node) {
        return;
    }
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);
    if (left_height - right_height > 1) { //left unbalanced
        if(getHeight(node->left->left) >= getHeight(node->left->right)) {
            rotateRightRef(node);
        }
        else {
            rotateRightDoubleRef(node);
        }
    }
    if (right_height - left_height > 1) { //right unbalanced
        if(getHeight(node->right->right) >= getHeight(node->right->left)) {
            rotateLeftRef(node);
        }
    }
    balance(node->left);
    balance(node->right);
}

template <typename T>
int BST<T>::count_leafs(BTNode<T>* node)
{
    if (!node) return 0;
    else if (node->isLeaf()) {
        return 1;
    }
    return count_leafs(node->left) + count_leafs(node->right);
}