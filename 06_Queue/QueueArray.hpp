#ifndef QUEUEARRAY_H
#define QUEUEARRYA_H

template <typename T, int size = 100>
class QueueArray {
public:
    QueueArray();
    int size() const;
    bool empty() const;
    bool full() const;

    void enqueue(const T& val);
    const T& dequeue();

private:
    T data[size]; // an array of 100 elements
    unsigned queue_size;
    int front_idx;
    int back_idx;
};

#endif