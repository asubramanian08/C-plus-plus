#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    set<string> fred = {"mary", "dhruva", "bob", "jared", "ted", "ken", "ananya"};
    set<string> betty = {"jared", "ananya", "dhruva", "julian", "victor", "mary", "ashish"};

    set<string> ceremony, invite, toCall, friends;
    set_intersection(fred.begin(), fred.end(), betty.begin(), betty.end(), inserter(ceremony, ceremony.begin()));
    set_symmetric_difference(fred.begin(), fred.end(), betty.begin(), betty.end(), inserter(invite, invite.begin()));
    set_difference(fred.begin(), fred.end(), betty.begin(), betty.end(), inserter(toCall, toCall.begin()));
    set_union(fred.begin(), fred.end(), betty.begin(), betty.end(), inserter(friends, friends.begin()));
    return 0;
}