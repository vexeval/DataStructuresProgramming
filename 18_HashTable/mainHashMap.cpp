#include "HashMap.hpp"
#include <iostream>

int main()
{
    HashMap<int, int> map;

    map.insert(111, 1);
    map.insert(222, 2);
    map.insert(333, 3);
    map.print();

    return 0;
}