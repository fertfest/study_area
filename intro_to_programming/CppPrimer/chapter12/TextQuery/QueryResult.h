#include <string>
#ifndef __QUERY_RESULT_H
#define __QUERY_RESULT_H

using line_no = std::vector<std::string>::size_type;
class QueryResult
{

    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {}

private:
    std::string sought;                             // word this query represents
    std::shared_ptr<std::set<line_no>> lines;       // lines it’s on
    std::shared_ptr<std::vector<std::string>> file; // input file
};
#endif