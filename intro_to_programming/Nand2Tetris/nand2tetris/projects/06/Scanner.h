#include <string>
#include "SymbolTable.h"
#include "AsmFileProcesser.h"
#ifndef __SCANNER_H
#define __SCANNER_H

class Scanner
{
private:
    SymbolTable st;
    AsmFileProcesser *afp;
    unsigned lineCounter = 0;

public:
    Scanner(const std::string &);
    ~Scanner();
    const SymbolTable &getSymbolTable() const;
    void scanning();
    void scanningLabels();
    void scanningVariables();
};

#endif