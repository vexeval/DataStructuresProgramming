#include <iostream>
#include "QueueDLL.hpp"
#include "QueueDLL.cpp"
#include "DLList.hpp"
#include "DLList.cpp"

int main()
{
    QueueDLL<int> queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.print();
    std::cout << "Dequeued " << queue.dequeue() << std::endl;
    queue.print();
    std::cout << "Dequeued " << queue.dequeue() << std::endl;
    queue.print();
    std::cout << "Dequeued " << queue.dequeue() << std::endl;
    
    try {
        queue.dequeue();
    } catch (std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }

    queue.print();

    return 0;
}