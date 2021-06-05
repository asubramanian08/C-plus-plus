#include <iostream>

//following structures were given -> TE2
//modified TE5 to operator<() and constuctors
struct A
{
    int x;
    virtual void callme() { std::cout << "A\n"; }
    virtual ~A() { std::cout << "A deleted\n"; }
    bool operator<(const A &a) { return x < a.x; }
    A(int x = 0) : x(x) {}
};
struct B : public A
{
    virtual void callme() { std::cout << "B\n"; }
    ~B() { std::cout << "B deleted\n"; }
    B() : A() {}
    B(int x) : A(x) {}
};