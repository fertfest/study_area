#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct PersonInfo
{
    /* data */
    string name;
    vector<string> phones;
};

int main(int argc, char const *argv[])
{
    string line, word;
    ifstream in("people");
    vector<PersonInfo> people;
    istringstream record;
    while (getline(in, line))
    {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }
    for (PersonInfo p : people)
    {
        cout << p.name << " ";
        for (string number : p.phones)
        {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}
