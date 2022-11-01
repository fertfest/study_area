#include <iostream>
#include <string>
#include "QueryResult.h"
using namespace std;
string make_plural(size_t times, string s, string b)
{
    if (times > 1)
    {
        return s + b;
    }
    return s;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines) // for every element in the set
        // don’t confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}