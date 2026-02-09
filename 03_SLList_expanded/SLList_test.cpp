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
    list.push_back("0");
    list.push_back("M");
    list.push_back("I");
    list.push_back("H");
    list.print();
    list.insert(3, "T");
    list.insert(4, "C");
    list.insert(6, "!", 2);
    list.print();

    list.rotate_right(7);
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