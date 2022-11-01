#include <stdexcept>
#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string &
StrBlobPtr::deref() const
{
    auto ref = check(curr, "dereference past end");
    return (*ref)[curr];
}

StrBlobPtr &
StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr
StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr
StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

bool StrBlobPtr::operator==(const StrBlobPtr &p) const
{
    auto p1 = wptr.lock().get();
    auto p2 = p.wptr.lock().get();

    return p1 == p2 && curr == p.curr;
}