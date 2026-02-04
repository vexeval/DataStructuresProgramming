#include <iostream>
#include "QueueArray.hpp"
#include "QueueArray.cpp"

int main()
{
    QueueArray<int, 10> queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.print();

    // while (!queue.empty()) {
    //     std::cout << queue.dequeue() << std::endl;
    // }

    queue.clear();
    queue.print();

    try {
        queue.dequeue();
    }
    catch (std::out_of_range ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}