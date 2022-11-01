#include <vector>
#include <iostream>
using namespace std;

vector<int> *factory()
{
    return new vector<int>;
}

void getElements(vector<int> *vints)
{
    int temp;
    while (cin >> temp)
    {
        vints->push_back(temp);
    }
}

void printElements(const vector<int> *vints)
{
    for (int n : *vints)
        cout << n << " ";
}

int main(int argc, char const *argv[])
{
    vector<int> *vints = factory();
    getElements(vints);
    printElements(vints);
    delete vints;
    return 0;
}
