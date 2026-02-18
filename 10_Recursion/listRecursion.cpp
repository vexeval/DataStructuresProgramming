#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* next;
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) { }
};

void print_list(Node* head);
void print_list_backwards(Node* head);
Node* reverse_list(Node* head);
Node* swap_pairs(Node* head);
Node* swap_helper(Node* first, Node* second);

void backtrack(std::vector<Node*>& nodes, int index);

int main(void)
{
    // create linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    std::cout << "Base list: \t\t";
    print_list(head);

    std::cout << "Printed backwards list: ";
    print_list_backwards(head);
    std::cout << "\n";
    
    std::cout << "Actually reversed list: ";
    head = reverse_list(head);
    print_list(head);
    
    std::cout << "Pair swapped list: \t";
    head = swap_pairs(head);
    print_list(head);

    return 0;
}

void print_list(Node* head)
{
    if (!head) {
        std::cout << std::endl;
        return;
    }

    std::cout << head->data << ' ';
    print_list(head->next);
}

void print_list_backwards(Node* head) // uses stack
{
    if (!head)
        return;

    print_list_backwards(head->next);
    std::cout << head->data << ' ';
}

Node* reverse_list(Node* head)
{
    if (!head || !head->next)
        return head;
    
    Node* p = reverse_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

Node* swap_pairs(Node* head)
{
    if (!head || !head->next) 
        return head;

    return swap_helper(head, head->next);
}

Node* swap_helper(Node* first, Node* second)
{
    first->next = swap_pairs(second->next); // link first node to result of the swap of remaining list
    second->next = first;
    return second; // return second node as new head of this pair
}

// Node* alt_swap(Node* head)
// {
//     if (!head || !head->next)
//         return head;

//     Node* nextPair = head->next->next;
//     head->next->next = head;
//     head = head->next;
//     head->next->next = alt_swap(nextPair);
//     return head;
// }

// void printAllPermutations(Node* head) // WIP
// {
//     std::vector<Node*> nodes;

//     while (head)
//     {
//         nodes.push_back(head->next);
//     }
// }

void backtrack(std::vector<Node*>& nodes, int index)
{
    if (index == nodes.size())
    {
        // current perm
        for (auto node : nodes)
            std::cout << node->data << ' ';
        
        std::cout << std::endl;
        return;
    }

    for (int i = index; i < nodes.size(); ++i)
    {
        // choose
        std::swap(nodes[index], nodes[i]);

        // explore
        backtrack(nodes, index + 1);

        // un-choose (backtrack)
        std::swap(nodes[index], nodes[i]);
    }
}