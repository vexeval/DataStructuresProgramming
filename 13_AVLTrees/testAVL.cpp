#include "AVLTree.hpp"
#include "AVLTree.cpp"

#include <iostream>
#include <string>

int main(void) {
    AVLTree<int> tree;
    // tree.insert(20);
    // tree.insert(1);
    // tree.insert(23);
    // tree.insert(22);
    // tree.insert(24);
    // tree.insert(26);
    // tree.insert(27);
    // tree.insert(28);
    // tree.insert(29);
    // tree.insert(19);
    // tree.insert(12);

    for (int i = 1; i < 20; i++) {
        std::cout << "Insert " << i << std::endl;
        tree.insert(i);
        tree.print();
    }
    
    std::cout << "\nDELETION\n\n";
    
    for (int i = 19; i >= 1; i--) {
        std::cout << "Remove " << i << std::endl;
        tree.remove(i);
        tree.print();
    }

    // tree.print();

    // tree.remove(12);
    
    return 0;
}


