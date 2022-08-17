#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    using namespace std;
    vector<int> values = {2, 3, 5, 6, 9};
    for (auto it = values.begin(); it != values.end(); it++)
    {
        *it = *it * 2;
    }

    for (const auto &val : values)
    {
        cout << val << " ";
    }
    return 0;
}
