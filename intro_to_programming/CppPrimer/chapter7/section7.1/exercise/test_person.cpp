#include "Person.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Person p1;
    Person p2;
    read(std::cin, p1);
    read(std::cin, p2);
    print(std::cout, p1) << std::endl;
    print(std::cout, p2);
    return 0;
}
