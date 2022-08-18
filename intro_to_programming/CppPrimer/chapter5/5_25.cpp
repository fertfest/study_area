#include <iostream>

int main(int argc, char const *argv[])
{
    int a;
    int b;
    while (true)
    {
        std::cin >> a >> b;
        try
        {
            if (b == 0)
                throw std::runtime_error("divide by zero!");
            std::cout << a / b;
            break;
        }
        catch (std::exception e)
        {
            std::cout << "Please input again:";
        }
    }
    return 0;
}