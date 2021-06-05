#include <functional>
#include <string>
using namespace std;

int main(void)
{
    //what is the point of invoke?
    int a = invoke([]()
                   { return 42; });
    int b = invoke([](int x, int y)
                   { return x + y; },
                   5, 2);
    string c = invoke([](string s1, string s2)
                      { return s1 + s2; },
                      "Hello", "World");
    return 0;
}