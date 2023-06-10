#include "Scanner.h"
#include <iostream>

Scanner::Scanner(const std::string &asmFile) : afp(new AsmFileProcesser(asmFile))
{
}

Scanner::~Scanner()
{
}

void Scanner::scanning()
{
    scanningLabels();
    scanningVariables();
    afp->close();
}

void Scanner::scanningLabels()
{
    std::string line;
    while ((line = afp->processOneLine()) != "null")
    {
        if (line[1] == 'l')
        {
            std::string labelName = line.substr(3, line.size() - 4);
            st.setLabelAddress(labelName, lineCounter);
        }
        else if (line[1] == 'c' || line[1] == 'a')
        {
            lineCounter++;
        }
        else
        {
            throw std::runtime_error("scanning: require a or c or l.");
        }
    }
    lineCounter = 0;
}

void Scanner::scanningVariables()
{
    std::string line;
    afp->backToHead();
    while ((line = afp->processOneLine()) != "null")
    {
        if (line[1] == 'a')
        {
            std::string valName = line.substr(3);
            bool isNumber = true;
            for (char c : valName)
            {
                if (!std::isdigit(c))
                {
                    isNumber = false;
                    break;
                }
            }

            if (!isNumber)
            {
                if (st.findAddress(valName) == -1)
                    st.setVariableAddress(valName);
            }
            lineCounter++;
        }
        else if (line[1] == 'c')
        {
            lineCounter++;
        }
        else if (line[1] == 'l')
        {
        }
        else
        {
            throw std::runtime_error("scanning: require a or c or l.");
        }
    }
}
const SymbolTable &
Scanner::getSymbolTable() const
{
    return st;
}
