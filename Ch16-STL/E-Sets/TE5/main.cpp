#include <unordered_set>
#include <set>
using namespace std;
#include "../Point.cpp"
#include "../../BucketStats.cpp"
#include "../../TimeMe.cpp"

//adds 1,000,000 point to a set
template <typename data>
void addPoints(data &set)
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            set.insert(point(i, j));
}

int main(void)
{
    unordered_set<point> uset, uset_time;
    set<point> set_time;
    addPoints(uset);
    bucket_stats(uset); //there is a printing problem look at it
    //The maximum chain is _____
    //why are there the lambda problems what is happening
    auto uset_add = TimeMe([addPoints(uset_time)]() {});
    auto set_add = TimeMe([addPoints(set_time)]() {});
    //It took ___ milliseconds for the uset and _____ for the set
    //help with the timing same problem as first comment
    //auto user_search = TimeMe([uset.search({500, 500})]() {});
    return 0;
}