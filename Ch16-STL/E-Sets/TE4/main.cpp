#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    set<string> groomsmen = {"mary", "dhruva", "bob", "jared", "ted", "ken", "ananya"};
    set<string> bridesmaids = {"jared", "ananya", "dhruva", "julian", "victor", "mary", "ashish"};
    set<string> ceremony;
    set_union(groomsmen.begin(), groomsmen.end(), bridesmaids.begin(), bridesmaids.end(), insert_iterator(ceremony, ceremony.begin()));
    // not sure what to do
    return 0;
}