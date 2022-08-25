#include <vector>
typedef double Money;

class Account
{
private:
    /* data */
    Money n;

public:
};

class NoDefault
{
public:
    NoDefault(int) {}
};

class C
{
public:
    NoDefault s;
    C() : s(0) {}
};

std::vector<C> vc(10);