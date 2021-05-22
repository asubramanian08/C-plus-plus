#include <memory>
#include <iostream>
using namespace std;
#include "../AB.cpp"

int main(void)
{
    shared_ptr<int> test = make_shared<int>(0);
    shared_ptr<A> pa;
    pa->x = 42;
    pa->callme();
    shared_ptr<A> pa2(pa);
    cout << pa.use_count() << endl;
    pa2 = nullptr;
    cout << pa.use_count() << endl;
    //the reference count decrements because one less thing points to it
    pa = nullptr;
    //This triggers the destructor of class A
    pa = shared_ptr<A>();
    pa.reset();
    //To get the physical memory I can call get()
    return 0;
}