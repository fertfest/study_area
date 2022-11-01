#include <string>
#include <memory>
#include "StrBlob.h"

#ifndef __CONST_STRBLOBPTR_H
#define __CONST_STRBLOBPTR_H

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string &deref() const;
    ConstStrBlobPtr &incr(); // prefix version
    bool operator==(const ConstStrBlobPtr &) const;

private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>>
    check(std::size_t, const std::string &) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // current position within the array
};

#endif