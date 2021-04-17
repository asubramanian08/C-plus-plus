#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
using namespace std;

int main(void)
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2;
    transform(v1.begin(), v1.end(), back_inserter(v2), [](int x) { return x * 10; });
    transform(v1.begin(), v1.end(), v2.begin(), plus<int>());
    transform(v2.begin(), v2.end(), v2.begin(), negate<int>());
    string str = "hello world";
    transform(str.begin(), str.end(), str.begin(), toupper);
    vector<string> vs1{"book", "good", "civil"};
    vector<string> vs2{"worm", "bye", "war"};
    vector<string> vs;
    //?
    return 0;
}