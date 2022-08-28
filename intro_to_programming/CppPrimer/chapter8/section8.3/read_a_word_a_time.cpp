#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ifstream ifs("../../transactions_input_file");
    std::vector<std::string> strs;
    std::string line;
    while (ifs >> line)
    {
        strs.push_back(line);
    }
    for (std::string str : strs)
    {
        std::istringstream iss(str);
        std::string word;
        while (iss >> word)
            std::cout << word << std::endl;
    }
    return 0;
}
