#include <iostream>

int main()
{
    double d = 3.33;
    const int &r = d;
    std::cout << r;
    return 0;
}