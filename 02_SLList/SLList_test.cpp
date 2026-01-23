#include "SLList.hpp"
#include <iostream>

int main(void)
{
    SLList H;
    H.push_front(19);
    H.push_front(21);
    H.push_front(68);
    H.print();
    return 19;
}