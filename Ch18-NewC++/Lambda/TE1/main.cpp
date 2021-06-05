#include <iostream>
#include <string>
#include <vector>
using namespace std;

int glob = -1;
int main(void)
{
    int x = 0, y = 1, z = 2;

    auto a = [x, y]
    { return x + y; };

    auto b = [&x, &y]
    { x = x + y; };

    //copied (changed exref to c)
    x = 1, y = 2;
    auto c = [&x, y]()
    { return x + y; };
    cout << c() << '\n';
    x = 10, y = 20;
    cout << c() << '\n';
    /**the values will be 3 and 12
     * x by & so it changed, copied y */

    //They are declared as int &

    //copied and some commented
    auto e = [/*glob*/]()
    { return glob + 1; };
    /**you can't capute globals because ?static
     * its works with out the capture */

    // ?

    static int stat = 4;
    //copied and some commented
    auto g = [/*stat*/]()
    { return stat + 1; };
    /**This has the same problem as a global
     * When it is remove everything works*/

    //copied and some commented
    int x = 3;
    auto add = [x](int y) { /*x = x + 1;*/ return x + y; };
    //it doesn't compile

    auto i1 = [w = 42]() {};
    auto i2 = [w = "hello"]() {};
    auto i3 = [w = string("hello")]() {};

    using fptype = int (*)(int);
    vector<fptype> j = {
        [](int x) { /*first*/  return x * 2; },
        [](int x) { /*second*/ return x * x; },
        [](int x) { /*third*/  return x / 4; }};
    int test = 10;
    for (auto func : j)
        test = func(test);
    cout << test << endl;

    //class given
    class A
    {
    public:
        int x;
        A(int x = 4) : x(x) { cout << "construct A\n"; }
        A(const A &a) : x(a.x) { cout << "a new copy was made\n"; }
        ~A() { cout << "A deleted\n"; }
        auto test_capture_this()
        {
            auto testme = [this]()
            { return x; };
            return testme;
        }
        auto test_capture_this_copy()
        {
            auto testme = [*this]()
            { return x; };
            return testme;
        }
    };
    A atest;
    auto t1 = atest.test_capture_this(); // doesn't print
    auto t2 = atest.test_capture_this();
    // doesn't make new object (infinate times) because it uses a pointer
    auto t3 = t2;
    auto t4 = t2;
    auto t5 = t2;
    auto t6 = t2;
    auto t7 = t2;
    // multiple pointers to the object are made
    //copied
    auto badthing = []()
    {
        A atest;
        //return atest.test_capture_this();
        return atest.test_capture_this_copy();
    };
    auto bt = badthing();
    cout << bt() << '\n';
    /**error
     * because the original object was deleted
     * is wouldn't happend if *_copy is used*/

    return 0;
}