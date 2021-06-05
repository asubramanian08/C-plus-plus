#include <iostream>
using namespace std;

#include "../AB.hpp"

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
    unique_ptr<B[]> parr = make_unique<B[]>(10);
    for (int i = 0; i < 10; i++)
        parr[i].x = 42;
    //I can free it using the reset method in unique_ptr
    parr.reset();
    //Distroys the array of 10 -> 10 A,B destructors called
    return 0;
}