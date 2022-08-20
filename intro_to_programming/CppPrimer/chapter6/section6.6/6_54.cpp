#include <vector>
int func(int, int) {}
std::vector<int (*)(int, int)> func_ptrs;
std::vector<decltype(func) *> func_ptrs1;

int main(int argc, char const *argv[])
{
    func_ptrs.push_back(func);
    func_ptrs.push_back(&func);
    return 0;
}
