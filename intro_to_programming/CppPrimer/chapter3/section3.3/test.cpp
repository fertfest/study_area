#include <string>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    vector<string> v1{10, "Hi"};
    vector<string> v2{"10", "Hi"};
    cout << "v1:" << endl;
    for (auto s : v1)
    {
        cout << s << endl;
    }
    cout << "v2:" << endl;
    for (auto s : v2)
    {
        cout << s << endl;
    }
    return 0;
}
