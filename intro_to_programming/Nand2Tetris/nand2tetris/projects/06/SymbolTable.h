#include <map>
#include <string>
#ifndef __SYMBOL_TABLE_H
#define __SYMBOL_TABLE_H

class SymbolTable
{
private:
    std::map<std::string, int> nameToAddress;
    int counter = 16;

public:
    SymbolTable();
    ~SymbolTable();
    int findAddress(const std::string &) const;
    void setLabelAddress(const std::string &, int);
    void setVariableAddress(const std::string &);
    const std::map<std::string, int> &content() const;
};

#endif