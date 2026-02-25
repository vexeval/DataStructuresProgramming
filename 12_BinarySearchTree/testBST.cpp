#include "BTNode.hpp"
#include "BST.hpp"
#include "BST.cpp"
#include <iostream>

int main(void)
{
    // BTNode<int>* root = new BTNode<int>(23);

    BST<int>* binaryST = new BST<int>();

    srand(0);

    int r1 = rand() % 100;
    int r2 = rand() % 100;
    int r3 = rand() % 100;
    int r4 = rand() % 100;

    std::cout << r1 << '\n';
    std::cout << r2 << '\n';
    std::cout << r3 << '\n';
    std::cout << r4 << '\n';

    binaryST->insert(r1);
    binaryST->insert(r2);
    binaryST->insert(r3);
    binaryST->insert(r4);
    binaryST->inorder();
    std::cout << "Height/Furthest Depth: " << binaryST->getFurthestDepth() << '\n';
    binaryST->display();

    BST<int> tree;
    tree.insert_recursive(4);
    tree.insert_recursive(8);
    tree.insert_recursive(3);
    tree.insert_recursive(7);

    // TODO test isFullTree
    // TODO search_parent (return address of the parent of node)

    BTNode<int>* node = tree.search(4);
    if (node) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not Found\n";
    }

    return 0;
}