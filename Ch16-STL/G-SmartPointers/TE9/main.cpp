#include <functional>
#include <memory>
using namespace std;

int main(void)
{
    //smart pointer or lambda code given
    using lambtype = function<int(int, int)>;
    auto shlamb = make_shared<lambtype>([](int x, int y)
                                        { return x + y; });
    auto unlamb = make_unique<lambtype>([](int x, int y)
                                        { return x - y; });

    //call the lambda -> could use invoke
    int shval = (*shlamb)(1, 2);
    int unval = (*unlamb)(1, 2);
    return 0;
}