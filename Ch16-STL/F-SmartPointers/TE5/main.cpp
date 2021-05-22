#include <memory>
#include <set>
using namespace std;
#include "../AB.cpp"

int main(void)
{
    set<unique_ptr<A>> set_unique1;
    for (int i = 0; i < 9; i++)
        set_unique1.insert(make_unique<A>(i));
    set<unique_ptr<A>> set_unique2;
    //set_unique2.insert(set_unique1.begin(), set_unique1.end()); //line copied
    //it didn't complie because there can only be one unique_ptr pointing to a memory
    set_unique2.merge(set_unique1);
    //everything from set_unique1 was moved into set_unique2
    return 0;
}