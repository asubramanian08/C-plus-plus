#include <iostream>
using namespace std;

//following structures were given
struct A
{
    int x;
    virtual void callme() { cout << "A\n"; }
    virtual ~A() { cout << "A deleted\n"; }
};
struct B : public A
{
    virtual void callme() { cout << "B\n"; }
    ~B() { cout << "B deleted\n"; }
};

int main(void)
{
    unique_ptr<A> p;
    p = make_unique<B>();
    //It works because B inherits from A
    p->callme();
    //It prints B (the B's callme func)
    p->x = 42;
    p = nullptr;
    //The memory gets freed
    p = make_unique<B>();
    p = make_unique<B>();
    //the old memory from p gets freed
    unique_ptr<B[]> parr(new B[10]);
    for (int i = 0; i < 10; i++)
        parr[i].x = 42;
    //I can free it using the reset method in unique_ptr
    parr.reset();
    //Distroys the array of 10 -> 10 A,B destructors called
    return 0;
}