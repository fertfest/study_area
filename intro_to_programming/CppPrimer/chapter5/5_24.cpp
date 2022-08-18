#include <iostream>

int main(int argc, char const *argv[])
{
    int a;
    int b;
    std::cin >> a >> b;
    if (b == 0)
        throw std::exception();
    std::cout << a / b;
    return 0;
}