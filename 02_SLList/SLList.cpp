#include "SLList.hpp"
#include <iostream>

SLList::SLList()
{
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

SLList::~SLList()
{
    clear();
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
    if (size() == 1) tail = head;
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

void SLList::push_back(int val)
{
    if (empty())
    {
        push_front(val);
        return;
    }
    tail->next = new SLLNode(val); // add node to the end
    tail = tail->next; // move tail

    list_size++;
}

void SLList::pop_front()
{
    if (empty()) return;

    SLLNode *prev_head = head;
    head = head->next;
    delete prev_head;
    list_size--;
    if (empty()) tail = head;
}

void SLList::pop_back()
{
    if (empty()) return;

    SLLNode* cur = head;

    for (int i = 0; i < list_size; i++)
    {
        // TODO WIP
    }
}

void SLList::clear()
{
    while (!empty())
        pop_front();
}

SLList& SLList::operator=(const SLList& other)
{
    
}