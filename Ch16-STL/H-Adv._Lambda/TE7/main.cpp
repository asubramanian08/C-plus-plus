#include <functional>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    using fptype = function<int(int)>;
    int junk = 0;
    //copied from TE1.j, added capture
    vector<fptype> j = {
        [junk](int x) { /*first*/  return x * 2; },
        [junk](int x) { /*second*/ return x * x; },
        [junk](int x) { /*third*/  return x / 4; }};
    int test = 10;
    for (auto func : j)
        test = func(test);
    cout << test << endl;
    return 0;
}