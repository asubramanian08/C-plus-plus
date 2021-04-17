#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

#define SIZE 2'000'000'000
//couldn't find the debugger timing
int main(void)
{
    vector<int> vi(SIZE);
    iota(vi.begin(), vi.end(), 1);
    find(vi.begin(), vi.end(), SIZE);
    binary_search(vi.begin(), vi.end(), SIZE);
    // binary search only makes log(n) compare
    // while find looks through every element
    return 0;
}