#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void)
{
    vector<int> vi = {10, 25, 25, 10, 30, 40};
    replace(vi.begin(), vi.end(), 25, 20);
    replace_if(
        vi.begin(), vi.end(), [](int x) { return x % 4 == 0; }, 4);
    fill(vi.end() - 3, vi.end(), 42);
    fill_n(vi.end() - 3, 3, 41);
    return 0;
}