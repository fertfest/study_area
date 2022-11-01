#include <stdexcept>
#include "ConstStrBlobPtr.h"

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
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
ConstStrBlobPtr::deref() const
{
    auto ref = check(curr, "dereference past end");
    return (*ref)[curr];
}

ConstStrBlobPtr &
ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr
StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr
StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
}

bool ConstStrBlobPtr::operator==(const ConstStrBlobPtr &p) const
{
    auto p1 = wptr.lock().get();
    auto p2 = p.wptr.lock().get();

    return p1 == p2 && curr == p.curr;
}