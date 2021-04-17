#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> vi = {6, 7, 2, -5, 7, 6, 6, 5, -1, 20, 6, 1};
    int count6 = count(vi.begin(), vi.end(), 6);
    int countOdd = count_if(vi.begin(), vi.end(), [](int x) { return x % 2 == 1; });
    //getting min and max (could do minmax_element)
    auto cmp = [](int x, int y) { return x < y; };
    int minEle = min_element(vi.begin(), vi.end(), cmp) - vi.begin();
    int maxEle = max_element(vi.begin(), vi.end(), cmp) - vi.begin();
    //sum?
    //remove duplicates
    sort(vi.begin(), vi.end());
    unique(vi.begin(), vi.end());
    transform(vi.begin(), vi.end(), vi.begin(), [](int x) { return x * 7; }); //?
    transform(vi.begin(), vi.end(), vi.begin(), [](int x) { if(x % 5 == 0) return x+100; return x; });               //?
    bool devis = any_of(vi.begin(), vi.end(), [](int x) { return (x % 9 == 0) || (x % 140 == 0) || (x % 240 == 0); });
    //seach for -7,7,14
    vector<int> sequence = {-7, 7, 14};
    int pos = search(vi.begin(), vi.end(), sequence) - vi.begin();
    vi[pos] = 4;
    vi[pos + 1] = 4;
    return 0;
}