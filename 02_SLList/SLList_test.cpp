#include "SLList.hpp"
#include <iostream>

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
    
    return 0;
}