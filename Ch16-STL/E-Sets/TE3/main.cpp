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

    set<string> test_set(test.begin(), test.end());
    return 0;
}