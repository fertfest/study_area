#include "AsmFileProcesser.h"
#include "ResolutionMan.h"
#include "SymbolTable.h"
#include "Scanner.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    ResolutionMan r(argv[1], argv[2]);
    r.resoluting();
    return 0;
}
