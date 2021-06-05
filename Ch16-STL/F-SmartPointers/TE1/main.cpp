#include <memory>
#include <iostream>
using namespace std;

//unique ptr maker of int 42
unique_ptr<int> upMaker()
{
    return make_unique<int>(42);
}

int main(void)
{
    unique_ptr<int> p1;
    if (!p1)
        p1 = make_unique<int>(42);
    cout << *p1 << endl;
    auto p2 = make_unique<int>(99);
    //unique_ptr<int> p59(99); SHOULD BE!!
    p1.swap(p2);
    unique_ptr<int[]> p3 = make_unique<int[]>(20);
    for (int i = 0; i < 20; i++)
        p3[i] = i;
    unique_ptr<int> test = upMaker();
    return 0;
}