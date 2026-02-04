#include <iostream>
#include "QueueDLL.hpp"
#include "QueueDLL.cpp"

int main()
{
    QueueDLL<int> queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.print();

    return 0;
}