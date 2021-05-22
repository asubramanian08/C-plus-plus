#include <iostream>
using std::cout;

//following structures were given -> TE2
//modified TE5 to operator<() and constuctors
struct A
{
    int x;
    virtual void callme() { cout << "A\n"; }
    virtual ~A() { cout << "A deleted\n"; }
    bool operator<(const A &a) { return x < a.x; }
    A(int x = 0) : x(x) {}
};
struct B : public A
{
    virtual void callme() { cout << "B\n"; }
    ~B() { cout << "B deleted\n"; }
    B() : A() {}
    B(int x) : A(x) {}
};