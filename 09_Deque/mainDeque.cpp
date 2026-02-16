#include "Deque.hpp"
#include "Deque.cpp"

#include <cmath>
#include <stdexcept>

int main(void) {
    Deque<int> deck;

    int i = 1;
    while (i < 10) {
        deck.push_back(pow(2, i));
        deck.push_front(pow(2, i + 1));
        i++;
        deck.print();
    }
    std::cout << "Size: " << deck.size() << std::endl;

    while (!deck.empty()) {
        std::cout << deck.front() << " " << deck.back() << std::endl;
        deck.pop_back();
        deck.pop_front();
    }

    try {
        deck.pop_back();
    }
    catch (std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}