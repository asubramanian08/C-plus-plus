#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    //initialize
    list<int> li1({1, 4, 5, 8, 9}), li2;
    vector<int> vi;
    deque<int> di;

    //copying
    copy(li1.begin(), li1.end(), back_inserter(vi));
    copy(vi.begin(), vi.end(), back_inserter(di));
    //copy(di.begin(), di.end(), front_inserter(li2));
    copy_backward(di.begin(), di.end(), back_inserter(li2));

    //A queue has no push back method
    return 0;
}