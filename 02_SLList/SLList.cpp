#include "SLList.hpp"
#include <iostream>

SLList::SLList()
{
    head = nullptr;
    list_size = 0;
}

unsigned SLList::size() const
{
    return list_size;
}

bool SLList::empty() const
{
    return (size() == 0);
}

void SLList::push_front(int val)
{
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;
    head = new SLLNode(val, head);
    list_size++;
}

void SLList::print() const
{
    std::cout << "{ ";
    SLLNode* cur = head;
    while (cur)
    {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next; // next node
    }
    std::cout << " }\n";
}

// TODO
void SLList::push_back(int val)
{
    SLLNode* newNode = new SLLNode(val, nullptr);
    if (head == nullptr)
    {
        head = newNode;
    }
}