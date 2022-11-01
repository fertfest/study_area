#include <iostream>
using namespace std;

int main()
{
    int *arr1 = new int[50];
    int *arr2 = new int[50]();

    for (int i = 0; i < 50; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < 50; i++)
        cout << arr2[i] << " ";
    return 0;
}
