#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main(void)
{
    vector<int> vi(20);
    fill(vi.begin(), vi.end(), 42);

    vi.clear();
    vi.resize(2000);
    generate(vi.begin(), vi.end(), [] { return uniform_int_distribution(); });

    int min, max;
    min = min_element(vi.begin(), vi.end()) - vi.begin();
    max = max_element(vi.begin(), vi.end()) - vi.begin();

    bool has5Mult = any_of(vi.begin(), vi.end(), [](int x) { return x % 5 == 0; });

    int num23Mult = count_if(vi.begin(), vi.end(), [](int x) { return (x % 2 == 0) || (x % 3 == 0); });

    return 0;
}