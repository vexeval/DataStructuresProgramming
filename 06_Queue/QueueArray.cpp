#include "QueueArray.hpp"

template <typename T>
void QueueArray<T>::QueueArray()
{
    queue_size = 0;
    front_idx = back_idx = 0;
}

template <typename T>
void QueueArray<T>::enqueue(const T& val)
{
    if (full()) return;

    data[back_idx] = val; // set the last element with value
    back_idx = (back_idx + 1) % size;
    queue_size++;
}