#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::size_t> word_counts;
    std::string word;
    while (std::cin >> word)
    {
        ++word_counts[word];
    }
    for (std::pair<std::string, std::size_t> word_count : word_counts)
    {
        std::cout << word_count.first << " occurs " << word_count.second << "time " << (word_count.second == 1 ? "" : "s")
                  << std::endl;
    }
    return 0;
}