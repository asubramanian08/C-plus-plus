#include <memory>
#include <iostream>
using namespace std;

int main(void)
{
    shared_ptr<int> sp = make_shared<int>(42);
    weak_ptr<int> wp(sp);
    cout << wp.use_count() << *wp.lock() << endl;
    shared_ptr<int> sp2(wp);
    sp.reset();
    if (wp.expired())
        cout << "Wp is expired" << endl;
    sp2.reset();
    if (wp.expired())
        cout << "Wp is expired" << endl;
    return 0;
}