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

    return 0;
}