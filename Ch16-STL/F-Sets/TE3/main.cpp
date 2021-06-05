#include <string>
#include <map>
#include <set>
using namespace std;

int main(void)
{
    //given
    multimap<string, int> test;
    test.insert({{"Ken", 42},
                 {"Dhruva", 21},
                 {"Darshan", 31},
                 {"Ken", 19},
                 {"Dhruva", 10},
                 {"Darshan", 5},
                 {"Ken", 5}});

    set<string> test_set;
    transform(test.begin(), test.end(), inserter(test_set, test_set.begin()), [](const pair<string, int> p)
              { return p.first; });
    return 0;
}