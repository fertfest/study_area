#include <string>
#include <iostream>
#include <cctype>

int main(int argc, char const *argv[])
{
    std::string s;
    std::cin >> s;
    for (const auto &c : s)
    {
        if (!std::ispunct(c))
        {
            std::cout << c << std::endl;
        }
    }
    return 0;
}
