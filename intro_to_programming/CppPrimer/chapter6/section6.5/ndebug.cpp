#include <iostream>

void fun()
{
    std::cout << __func__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
    std::cout << __TIME__ << std::endl;
    std::cout << __DATE__ << std::endl;
}

int main(int argc, char const *argv[])
{
    fun();
    return 0;
}
