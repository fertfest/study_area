#include <iostream>
#include <stdexcept>

int main(int argc, char const *argv[])
{
    throw std::exception();
    throw std::runtime_error("hell");
    std::cout << "hello world!";
    return 0;
}
