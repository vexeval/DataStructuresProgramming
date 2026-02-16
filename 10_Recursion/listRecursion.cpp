#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) {

    }
};

void print_list(Node* head);
void print_list_backwards(Node* head);
Node* reverse_list(Node* head);
Node* swap_pairs(Node* head); // TODO: w/o a temp variable

int main(void)
{
    // create linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    print_list(head);
    print_list_backwards(head);
    std::cout << std::endl;
    
    head = reverse_list(head);
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