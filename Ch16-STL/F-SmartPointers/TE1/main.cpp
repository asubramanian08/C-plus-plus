#include <memory>
#include <iostream>
using namespace std;

//unique ptr maker of int 42
unique_ptr<int> upMaker()
{
    return unique_ptr<int>(new int(42));
}

int main(void)
{
    unique_ptr<int> p1;
    if (!p1)
        p1 = make_unique<int>(42);
    cout << p1;
    unique_ptr<int> p2(new int(99));
    p1.swap(p2);
    unique_ptr<int[]> p3(new int[20]);
    for (int i = 0; i < 20; i++)
        p3[i] = i;
    unique_ptr<int> test = upMaker();
    return 0;
}