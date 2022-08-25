struct X
{
    friend void f() {}
    void g();
    void h();
};

void f();

void h() { return f(); }