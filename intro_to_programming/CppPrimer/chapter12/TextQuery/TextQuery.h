#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include "QueryResult.h"

#ifndef __TEXT_QUERY_H
#define __TEXT_QUERY_H

class QueryResult; // declaration needed for return type in the query function
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    std::map<std::string,
             std::shared_ptr<std::set<line_no>>>
        wm;
};

#endif