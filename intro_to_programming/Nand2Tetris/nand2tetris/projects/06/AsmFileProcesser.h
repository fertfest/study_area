#include <string>
#include <fstream>
#ifndef __ASM_FILE_PROCESSER_H
#define __ASM_FILE_PROCESSER_H

class AsmFileProcesser
{
private:
    std::ifstream asmFile;

public:
    AsmFileProcesser(std::string);
    ~AsmFileProcesser();
    std::string processOneLine();
    int isCOrA(std::string);
    void backToHead();
    void close();
};

#endif