#include <memory>
#include <set>
using namespace std;

auto cmp = [](const unique_ptr<int> &up1, const unique_ptr<int> &up2)
{
    return *up1 < *up2;
};

int main(void)
{
    set<unique_ptr<int>> SUP;
    //set<unique_ptr<int>, decltype(cmp)> SUP(cmp);
    SUP.insert(make_unique<int>(1));
    SUP.insert(make_unique<int>(1));
    //overload the compare -> insead for compareing memory address
    return 0;
}