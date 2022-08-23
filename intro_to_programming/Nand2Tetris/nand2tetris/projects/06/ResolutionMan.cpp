#include "ResolutionMan.h"
#include <bitset>
#include <iostream>

ResolutionMan::ResolutionMan(const std::string &afn, const std::string &hfn)
    : asmFileName(afn), scanner(afn), os(hfn)
{
}

ResolutionMan::~ResolutionMan()
{
    delete afp;
}

void ResolutionMan::resoluting()
{
    scanner.scanning();
    afp = new AsmFileProcesser(asmFileName);
    while (processOneLine())
    {
    }
}

bool ResolutionMan::processOneLine()
{
    std::string line = afp->processOneLine();
    if (line == "null")
        return false;
    if (line[1] == 'l')
    {
        return true;
    }
    else if (line[1] == 'a')
    {
        std::string content = line.substr(3);
        bool isNumber = true;
        for (char c : content)
        {
            if (!isdigit(c))
                isNumber = false;
        }
        int number;
        if (isNumber)
        {
            number = std::stoi(content);
        }
        else
        {
            number = scanner.getSymbolTable().findAddress(content);
        }

        os << std::bitset<16>(number) << std::endl;
        return true;
    }
    else if (line[1] == 'c')
    {
        std::string ins_string = line.substr(2);
        int instruction = 0;
        int index_of_equal_sign = ins_string.find_first_of("=");
        int index_of_semicolon = ins_string.find_first_of(";");
        std::string comp;
        if (index_of_equal_sign != -1)
        {
            // no jmp
            comp = ins_string.substr(index_of_equal_sign + 1);
        }
        else if (index_of_semicolon != -1)
        {
            for (int i = 0; i < index_of_semicolon; i++)
            {
                comp += ins_string[i];
            }
        }
        std::cout << comp << std::endl;
        bool hasA = false;
        bool hasM = false;
        bool hasD = false;
        bool has1 = false;
        bool has0 = false;
        bool hasAnd = false;
        bool hasOr = false;
        bool hasMinus = false;
        bool hasAdd = false;
        bool hasNot = false;

        for (char c : comp)
        {
            if ('A' == c)
                hasA = true;
            if ('M' == c)
                hasM = true;
            if ('D' == c)
                hasD = true;
            if ('1' == c)
                has1 = true;
            if ('0' == c)
                has0 = true;
            if ('&' == c)
                hasAnd = true;
            if ('|' == c)
                hasOr = true;
            if ('-' == c)
                hasMinus = true;
            if ('+' == c)
                hasAdd = true;
            if ('!' == c)
                hasNot = true;
        }
        int mask = 0;
        if (hasM)
        {
            mask += 64;
        }
        if (!hasD)
        {
            mask += 32;
        }
        if (hasOr)
            mask += 21;
        if (comp == "A-D" || comp == "M-D")
            mask += 7;
        if ("D-A" == comp || "D-M" == comp || "-A" == comp || "-M" == comp)
            mask += 19;
        if ("D+A" == comp || "D+M" == comp)
            mask += 2;
        if ("A-1" == comp || "M-1" == comp)
            mask += 18;
        if ("D-1" == comp)
            mask += 14;
        if ("A+1" == comp || "M+1" == comp)
            mask += 23;
        if ("D+1" == comp)
            mask += 31;
        if ("-D" == comp)
            mask += 15;
        if ("!A" == comp || "!M" == comp)
            mask += 17;
        if ("!D" == comp)
            mask += 13;
        if ("A" == comp || "M" == comp)
            mask += 16;
        if ("D" == comp)
            mask += 12;
        if ("-1" == comp)
            mask += 26;
        if ("1" == comp)
            mask += 31;
        if ("0" == comp)
            mask += 10;
        mask <<= 6;
        instruction += mask;

        if (index_of_equal_sign != -1)
        {
            std::string des;
            for (int i = 0; i < index_of_equal_sign; i++)
            {
                des += ins_string[i];
            }
            int mask = 0;
            for (char c : des)
            {
                if (c == 'A')
                {
                    mask += 4;
                }
                if (c == 'D')
                {
                    mask += 2;
                }
                if (c == 'M')
                {
                    mask += 1;
                }
            }
            mask <<= 3;
            instruction |= mask;
        }
        if (index_of_semicolon != -1)
        {
            std::string jmp = ins_string.substr(index_of_semicolon + 1);
            int mask = 0;
            if ("JGT" == jmp)
            {
                mask = 1;
            }
            else if ("JEQ" == jmp)
            {
                mask = 2;
            }
            else if ("JGE" == jmp)
            {
                mask = 3;
            }
            else if ("JLT" == jmp)
            {
                mask = 4;
            }
            else if ("JNE" == jmp)
            {
                mask = 5;
            }
            else if ("JLE" == jmp)
            {
                mask = 6;
            }
            else if ("JMP" == jmp)
            {
                mask = 7;
            }
            instruction += mask;
        }

        // set the highest 3 bits to 1.
        mask = 7;
        mask <<= 13;
        instruction |= mask;

        os << std::bitset<16>(instruction) << std::endl;
        return true;
    }
    else
    {
        throw std::runtime_error("Resolutionman::processOneLine: not a, c, l?");
    }
    throw std::runtime_error("Resolutionman::processOneLine: unexpected error");
    return false;
}