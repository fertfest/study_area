#include <iostream>

int main(int argc, char const *argv[])
{
    std::string result;
    for (int i = 1; i < argc; i++)
    {
        result += argv[i];
    }
    std::cout << result;
    return 0;
}
