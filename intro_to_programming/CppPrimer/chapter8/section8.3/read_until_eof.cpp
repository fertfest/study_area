#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

istream &read_until_eof(istream &is)
{
    while (is && !is.eof())
    {
        string line;
        getline(is, line);
        cout << line << std::endl;
    }
    is.clear();
    return is;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::string line = "Hello world yes!\nWhat the fuck!\nhello!";
    std::istringstream iss(line);
    read_until_eof(iss);
    return 0;
}
