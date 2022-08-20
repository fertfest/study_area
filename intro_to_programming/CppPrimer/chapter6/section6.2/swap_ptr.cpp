#include <iostream>

using namespace std;

void swap_ptr(int *(&p1), int *(&p2))
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3};
    int *p1 = arr;
    int *p2 = arr + 2;
    cout << *p1 << " " << *p2 << endl;
    swap_ptr(p1, p2);
    cout << *p1 << " " << *p2 << endl;
    return 0;
}