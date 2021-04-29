#include <vector>
using namespace std;

auto divBy(int x)
{
    return [x](int val) { return val % x == 0; };
}

int main(void)
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vi.erase(remove_if(vi.begin(), vi.end(), divBy(3)), vi.end());
    return 0;
}