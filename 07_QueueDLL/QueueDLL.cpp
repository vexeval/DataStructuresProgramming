#include <iostream>
#include "QueueDLL.hpp"
#include "DLList.hpp"

// template <typename T>
// QueueDLL<T>::QueueDLL()
// {
//     data = new DLList<T>;
// }

template <typename T>
void QueueDLL<T>::enqueue(const T& val)
{
    data.push_back(val);
}

template <typename T>
const T QueueDLL<T>::dequeue()
{
    if (!empty())
    {
        T temp = data.front();
        data.pop_front();
        return temp;
    }
    else
    {
        throw std::out_of_range("Empty list");
    }
}

template <typename T>
void QueueDLL<T>::print() const
{
    if (size() == 0) return;
    data.print();
}

template <typename T>
int QueueDLL<T>::size() const
{
    return data.size();
}

template <typename T>
bool QueueDLL<T>::empty() const
{
    return this->size() == 0;
}

template <typename T>
void QueueDLL<T>::clear()
{
    data.clear();
}

template <typename T>
const T& QueueDLL<T>::front() const
{
    return data.front();
}