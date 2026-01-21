#include "SLLNode.hpp"
#include <iostream>

int main(void)
{
    // Create SLL Nodes
    SLLNode *n1 = new SLLNode(1000);
    SLLNode *n2 = new SLLNode(2000);
    SLLNode *n3 = new SLLNode(3000);
    SLLNode *n4 = new SLLNode(4000);

    SLLNode *b = new SLLNode(60);
    b->next = new SLLNode(70);
    b->next->next = new SLLNode(80);

    // Link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Iterate through the nodes (linked list)
    SLLNode *cur = n1;
    while (cur != nullptr)
    {
        std::cout << cur->data;
        if (cur->next != nullptr) std::cout << " -> ";
        else std::cout << std::endl;
        cur = cur->next;
    }

    // Free the memory
    delete n1->next->next->next;
    delete n1->next->next;
    delete n1->next;
    delete n1;

    return 0;
}