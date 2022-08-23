#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
    nameToAddress["SP"] = 0;
    nameToAddress["LCL"] = 1;
    nameToAddress["ARG"] = 2;
    nameToAddress["THIS"] = 3;
    nameToAddress["THAT"] = 4;
    nameToAddress["R0"] = 0;
    nameToAddress["R1"] = 1;
    nameToAddress["R2"] = 2;
    nameToAddress["R3"] = 3;
    nameToAddress["R4"] = 4;
    nameToAddress["R5"] = 5;
    nameToAddress["R6"] = 6;
    nameToAddress["R7"] = 7;
    nameToAddress["R8"] = 8;
    nameToAddress["R9"] = 9;
    nameToAddress["R10"] = 10;
    nameToAddress["R11"] = 11;
    nameToAddress["R12"] = 12;
    nameToAddress["R13"] = 13;
    nameToAddress["R14"] = 14;
    nameToAddress["R15"] = 15;
    nameToAddress["SCREEN"] = 16384;
    nameToAddress["KBD"] = 24576;
}

SymbolTable::~SymbolTable()
{
}

int SymbolTable::findAddress(const std::string &symbol) const
{
    auto addressIter = nameToAddress.find(symbol);
    if (addressIter == nameToAddress.end())
    {
        return -1;
    }
    return (*addressIter).second;
}

void SymbolTable::setLabelAddress(const std::string &symbol, int address)
{
    nameToAddress[symbol] = address;
}

void SymbolTable::setVariableAddress(const std::string &val)
{
    nameToAddress[val] = counter++;
}

const std::map<std::string, int> &SymbolTable::content() const
{
    return nameToAddress;
}