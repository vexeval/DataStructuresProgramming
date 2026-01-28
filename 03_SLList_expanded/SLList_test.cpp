#include "SLList.hpp"
#include "SLList.cpp"
#include <iostream>
#include <string>

// void test(SLList list) {
//     // Test copy constructor and operator=
//     SLList l2;
//     l2 = list;
//     l2.print();
// }

int main(void)
{
    SLList<std::string> list;
    list.push_front("M");
    list.push_front("I");
    list.push_front("T");
    list.push_front("C");
    list.push_front("H");
    list.print();
    // H.pop_front();
    // H.print();
    // std::cout << "====\n";

    // test(H);

    // while (!H.empty()) {
    //     H.pop_back();
    //     H.print();
    // }
    
    return 0;
}