#include "AsmFileProcesser.h"
#include <cctype>
#include <iostream>

AsmFileProcesser::AsmFileProcesser(std::string fileName) : asmFile(fileName)
{
}

AsmFileProcesser::~AsmFileProcesser()
{
}

std::string
AsmFileProcesser::processOneLine()
{
    std::string line;
    while (!asmFile.eof() && getline(asmFile, line))
    {
        // process blank char
        char *temp = new char[line.size() + 1];
        int count = 0;
        for (char c : line)
        {
            if (c != ' ' && c != '\t' && c != 10 && c != 13)
            {
                temp[count++] = c;
            }
        }
        temp[count] = '\0';
        line = temp;
        if (line.size() > 0 && line[0] != '/')
            break;
    }
    int index_of_slash = line.find_first_of('/');
    if (index_of_slash != -1)
        line = line.substr(0, index_of_slash);
    if (line.size() == 0)
        return "null";

    int tag = isCOrA(line);
    if (tag == 0)
    {
        line = "`a" + line;
    }
    else if (tag == 1)
    {
        line = "`l" + line;
    }
    else if (tag == 2)
    {
        line = "`c" + line;
    }
    else
    {
        throw std::runtime_error("processOneLine: why the tag is not 0 or 1 or 2?");
    }
    return line;
}

/**
 * @param instruction: instruction string to judge
 * @return true: c instruction
 * @return false: a instruction
 * @description: determine a string is a c or a instruction, if the format of the
 * string is neither a "a" instruction nor a "c" instruction,and is not a label throw a runtime error.
 */
int AsmFileProcesser::isCOrA(std::string instruction)
{
    if (instruction.size() == 0)
        throw std::runtime_error("isCOrA: argument is a empty string");
    int tag;
    if (instruction[0] == '@')
    {
        tag = 0;
    }
    else if (instruction[0] == '(')
    {
        tag = 1;
    }
    else
    {
        tag = 2;
    }
    return tag;
}

void AsmFileProcesser::backToHead()
{
    asmFile.clear();
    asmFile.seekg(0, std::ios::beg);
}

void AsmFileProcesser::close()
{
    asmFile.close();
}