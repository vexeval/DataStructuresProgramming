#include "MinHeap.hpp"
#include "MinHeap.cpp"
#include <cstdlib>

int main(void) {
    MinHeap<int> heap;
    
    for (int i = 0; i < 10; i++) {
        heap.insert(rand() % 1000);
    }

    heap.print();

    return 0;
}