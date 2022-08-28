#include <iostream>
#include <fstream>
using namespace std;

istream &read_until_eof(istream &is)
{
    while (!is.eof())
    {
        string line;
        getline(is, line);
        cout << line;
    }
    is.clear();
    return is;
}

int main(int argc, char const *argv[])
{
    /* code */
    read_until_eof(cin);
    return 0;
}
