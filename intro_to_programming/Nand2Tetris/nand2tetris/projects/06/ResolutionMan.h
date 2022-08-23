#include "Scanner.h"
#include "AsmFileProcesser.h"
#include <fstream>
#ifndef __RESOLUTION_MAN_H
#define __RESOLUTION_MAN_H

class ResolutionMan
{
private:
    /* data */
    Scanner scanner;
    AsmFileProcesser *afp;
    std::string asmFileName;
    std::string hackFileName;
    std::ofstream os;

public:
    ResolutionMan(const std::string &afn, const std::string &hfn);
    ~ResolutionMan();

    void resoluting();
    bool processOneLine();
};

#endif