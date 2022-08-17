#include <string>
#include <iostream>
#include <vector>
#include <cctype>

int main(int argc, char const *argv[])
{
    using namespace std;
    vector<string> text{"Hello", "World!", "yes", "it's good", "", "sfa", "nothing to do"};
    for (auto &word : text)
    {
        for (auto &c : word)
        {
            c = toupper(c);
        }
    }
    for (auto it = text.cbegin(); it != text.cend(); it++)
    {
        cout << *it;
    }
    return 0;
}
