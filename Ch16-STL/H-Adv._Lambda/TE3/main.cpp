#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main(void)
{
    auto cap = [](string &str) { /*string::at throws*/ str[0] = toupper(str.at(0)); };
    vector<string> vs = {"hi ", "bob ", "is ", "my ", "name."};
    auto myapply = [](auto container, auto func)
    {
        for (auto item : container)
            func(item);
    };
    myapply(vs, cap);
    vector<int> vi(11);
    iota(vi.begin(), vi.end(), 0);
    auto mult5 = [](int &x) { /*multiply by 5*/ x *= 5; };
    myapply(vi, mult5);

    auto myaccumulate = [](auto begin, decltype(begin) end, auto init)
    {
        for (auto it = begin; it != end; it++)
            init += *it;
        return init;
    };
    int accInt = myaccumulate(vi.begin(), vi.end(), 0);
    string accStr = myaccumulate(vs.begin(), vs.end(), string());

    auto swap = [](auto &item1, decltype(item1) &item2)
    {
        auto temp = item1;
        item1 = item2;
        item2 = temp;
    };
    int a = 0, b = 1;
    swap(a, b);

    auto myreplace = [](auto begin, decltype(begin) end, auto from, decltype(from) to)
    {
        for (auto it = begin; it != end; it++)
            if (*it == from)
                *it = to;
    };
    myreplace(vs.begin(), vs.end(), vs[1], "jeffry ");
    return 0;
}