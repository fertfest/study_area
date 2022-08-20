#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> nums)
{
    int result = 0;
    auto c_iter = nums.begin();
    while (c_iter != nums.end())
    {
        result += *(c_iter++);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << sum({1, 2, 3, 4, 5});
    // if no return statement in main
    // return 0 as default
}
