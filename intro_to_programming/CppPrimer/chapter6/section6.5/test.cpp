#include <iostream>

int func(int a = 3, double d)
{
    return a * d;
}

int main(int argc, char const *argv[])
{
    std::cout << func(3.2);
    return 0;
}
