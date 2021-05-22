#include <memory>
#include <iostream>
using namespace std;

//what to do instead -> use week pointers
struct circ
{
public:
    weak_ptr<circ> sptr;
    void setp(shared_ptr<circ> &p) { sptr = p; }
    ~circ() { cout << "circ deleted\n"; }
};

int main(void)
{
    //the code is a bad idea because there is a circular reference and no memory will be deleted
    auto cp = make_shared<circ>();
    cp->setp(cp);
    cp.reset();
    return 0;
}