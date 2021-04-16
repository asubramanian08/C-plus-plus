#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main(void)
{
    //make the vector
    vector<int> vi;
    vi.resize(10);
    generate(vi.begin(), vi.end(), [] { static int val = 0; val++;  return val; });

    //find the sum of 10
    int sum10 = 0;
    for (auto iter = vi.begin(); iter != vi.end(); iter++)
        sum10 += *iter;

    //find the sum of 5
    int sum5 = 0;
    for (auto iter = vi.begin(); iter != vi.begin() + 5; iter++)
        sum5 += *iter;

    //make the list
    list<int> li(vi.begin(), vi.end());

    //find 10 sum of list
    int sum10 = 0;
    for (auto iter = li.begin(); iter != li.end(); iter++)
        sum10 += *iter;

    //the code is the same except for the variable
    return 0;
}