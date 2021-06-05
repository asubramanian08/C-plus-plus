#include <unordered_set>
#include <set>
#include <chrono>
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
    //The maximum chain is: 19

    auto uset_add = TimeMe([&uset_time]()
                           { addPoints(uset_time); });
    auto set_add = TimeMe([&set_time]()
                          { addPoints(set_time); });
    //It took 2136 milliseconds for the uset and 3998 for the set

    auto uset_search = TimeMe<chrono::nanoseconds>([&uset_time]()
                                                   { uset_time.find({500, 500}); });
    auto set_search = TimeMe<chrono::nanoseconds>([&set_time]()
                                                  { set_time.find({500, 500}); });
    //It took 1501 nanoseconds for the uset and 3762 for the set

    // The (uset) is faster for insert and (uset) is faster for the find
    // Find out how much faster -> subtract to values
    return 0;
}