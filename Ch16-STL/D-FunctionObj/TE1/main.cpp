#include <vector>
#include <algorithm>
using namespace std;

int genFunc(void)
{
    static int val = -1;
    return ++val;
}

class functor
{
private:
    int val = -1;

public:
    int operator()(void) { return ++val; }
};

int main(void)
{
    vector<int> vi;
    vi.resize(20);
    generate_n(vi.begin(), 20, genFunc);
    functor gen;
    generate_n(vi.begin(), 20, gen);
    int val = -1;
    generate_n(vi.begin(), 20, [&val] { return ++val; });
    return 0;
}