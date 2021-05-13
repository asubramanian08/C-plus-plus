#include <set>
using namespace std;
#include "../Point.cpp"

int main(void)
{
    set<point> pts;
    pts.insert({100, 700});
    pts.insert({500, 500});
    auto search = pts.find({500, 500});
    /**
     * It didn't find the right element because it think the 2 set values are the same
     * To fix that if the distance is equal I could compare the point values (x then y)
     */
    return 0;
}