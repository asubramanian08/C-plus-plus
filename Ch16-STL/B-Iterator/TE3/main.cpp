#include <list>
using namespace std;

int main(void)
{
    list<int> list5, list10;

    //generate 5
    list5.resize(101);
    generate(list5.begin(), list5.end(), [] { static int count = 100; count--;  return count + 1; });
    list5.remove_if([](int x) { return x % 5 != 0; });

    //generate 10
    list10.resize(101);
    generate(list10.begin(), list10.end(), [] { static int count = 0; count++;  return count - 1; });
    list10.remove_if([](int x) { return x % 10 != 0; });

    //merge
    list5.merge(list10);

    //unique
    list5.sort();
    list5.unique();

    return 0;
}