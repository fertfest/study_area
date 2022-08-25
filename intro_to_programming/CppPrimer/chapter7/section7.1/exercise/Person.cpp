#include "Person.h"

std::istream &
read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &
print(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.address;
    return os;
}
