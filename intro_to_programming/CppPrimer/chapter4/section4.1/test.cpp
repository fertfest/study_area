#include <iostream>

int main()
{
    using namespace std;
    cout << "char: " << sizeof(char) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "int&: " << sizeof(int &) << endl;
    cout << "double&: " << sizeof(double &) << endl;
    return 0;
}