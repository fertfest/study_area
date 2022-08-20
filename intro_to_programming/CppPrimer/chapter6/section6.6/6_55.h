#include <vector>
namespace myFuncs
{
    inline int add(int a, int b)
    {
        return a + b;
    }

    inline int sub(int a, int b)
    {
        return a - b;
    }

    inline int div(int a, int b)
    {
        return a / b;
    }

    inline int mul(int a, int b)
    {
        return a * b;
    }

    std::vector<int (*)(int, int)> func_ptrs;
};