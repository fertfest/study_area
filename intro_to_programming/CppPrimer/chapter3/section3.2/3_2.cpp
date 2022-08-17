#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::getline;
    using std::string;
    string newWord;
    string word;
    // while (getline(cin, line))
    // {
    //     cout << line << std::endl;
    // }

    while (cin >> word)
    {
        cout << word << std::endl;
    }
    return 0;
}
