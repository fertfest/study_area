#include <iostream>
#include <map>
#include <set>
#include <cctype>
using namespace std;
int main()
{
    set<string> punctuations = {"!", ",", "?", ".", ":", "..."};
    map<string, size_t> ignore_case_counts;
    string word;
    while (cin >> word)
    {
        for (char &c : word)
            c = tolower(c);
        if (punctuations.find(word) == punctuations.end())
            ++ignore_case_counts[word];
    }
    for (std::pair<std::string, std::size_t> word_count : ignore_case_counts)
    {
        std::cout << word_count.first << " occurs " << word_count.second << "time " << (word_count.second == 1 ? "" : "s")
                  << std::endl;
    }
    return 0;
}