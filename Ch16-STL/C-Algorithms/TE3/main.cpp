#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main(void)
{
    vector<int> vi = {6, 7, 2, -5, 7, 6, 6, 5, -1, 20, 6, 1};
    int count6 = count(vi.begin(), vi.end(), 6);
    int countOdd = count_if(vi.begin(), vi.end(), [](int x) { return x % 2 == 1; });
    auto min_max = minmax_element(vi.begin(), vi.end()); //pair of iterators
    int sum = accumulate(vi.begin(), vi.end(), 0);
    int mult = accumulate(vi.begin(), vi.end(), 1, multiplies<int>()); //not in questions
    //remove duplicates -> 2
    sort(vi.begin(), vi.end());
    unique(vi.begin(), vi.end());
    transform(vi.begin(), vi.end(), vi.begin(), [](int x) { return x * 7; });
    transform(vi.begin(), vi.end(), vi.begin(), [](int x) { if(x % 5 == 0) return x+100; return x; }); //find_if 4 lines
    bool devis = any_of(vi.begin(), vi.end(), [](int x) { return (x % 9 == 0) || (x % 140 == 0) || (x % 240 == 0); });
    //seach for -7,7,14 -> 4
    vector<int> sequence = {-7, 7, 14};
    auto pos = search(vi.begin(), vi.end(), sequence.begin(), sequence.end());
    if (pos != vi.end())
        *pos = *(pos + 1) = 4;
    return 0;
}