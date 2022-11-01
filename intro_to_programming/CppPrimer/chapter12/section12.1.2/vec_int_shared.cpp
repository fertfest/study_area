#include <vector>
#include <iostream>
#include <memory>
using namespace std;

shared_ptr<vector<int>> factory()
{
    return make_shared<vector<int>>();
}

void getElements(shared_ptr<vector<int>> vints)
{
    int temp;
    while (cin >> temp)
    {
        vints->push_back(temp);
    }
}

void printElements(shared_ptr<const vector<int>> vints)
{
    for (int n : *vints)
        cout << n << " ";
}

int main(int argc, char const *argv[])
{
    shared_ptr<vector<int>> vints = factory();
    getElements(vints);
    printElements(vints);
    return 0;
}
