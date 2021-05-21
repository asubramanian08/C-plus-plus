#include <iostream>
using namespace std;

//following structures were given
struct A
{
    int x;
    virtual void callme() { cout << "A\n"; }
    virtual ~A() { cout << "A-gone\n"; }
};
struct B : public A
{
    virtual void callme() { cout << "B\n"; }
    ~B() { cout << "B-gone\n"; }
};

int main(void)
{
    unique_ptr<A> p;
    p = make_unique<B>();
    //It works because B inherits from A
    p.get()->callme();
    //It prints B (the B's call me func)
    p.get()->x = 42;
    p = nullptr;
    //The memory gets freed
    //part e??
    unique_ptr<B[]> parr(new B[10]);
    for (int i = 0; i < 10; i++)
        parr[i].x = 42;
    //part g??
    return 0;
}