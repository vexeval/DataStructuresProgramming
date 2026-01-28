#include "SLList.hpp"
#include <iostream>

void test(SLList list) {
    // Test copy constructor and operator=
    SLList l2;
    l2 = list;
    l2.print();
}

int main(void)
{
    SLList H;
    H.push_front(19);
    H.push_front(21);
    H.push_front(68);
    H.push_back(985);
    H.push_back(915);
    H.print();
    H.pop_front();
    H.print();
    std::cout << "====\n";

    test(H);

    while (!H.empty()) {
        H.pop_back();
        H.print();
    }
    
    return 0;
}