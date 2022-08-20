#include "6_55.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    myFuncs::func_ptrs.push_back(myFuncs::add);
    myFuncs::func_ptrs.push_back(myFuncs::sub);
    myFuncs::func_ptrs.push_back(myFuncs::div);
    myFuncs::func_ptrs.push_back(myFuncs::mul);

    for (auto func : myFuncs::func_ptrs)
    {
        std::cout << func(15, 6) << std::endl;
    }
    for (auto func : myFuncs::func_ptrs)
    {
        std::cout << (*func)(15, 6) << std::endl;
    }
    return 0;
}
