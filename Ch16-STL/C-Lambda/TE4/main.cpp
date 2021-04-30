#include <vector>
#include <algorithm>
using namespace std;

template <typename Iter, typename Func>
void forEach(Iter start, Iter end, Func function)
{
    for (auto curr = start; curr != end; curr++)
        function(*curr);
}

int main(void)
{
    vector<int> vi;
    vi.resize(20);
    forEach(vi.begin(), vi.end(), [](int &x) { x = 1; });
    return 0;
}