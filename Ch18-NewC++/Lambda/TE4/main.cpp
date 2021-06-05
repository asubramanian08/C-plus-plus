#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename Func1, typename Func2>
auto compose(Func1 f1, Func2 f2)
{
    return [=](auto x)
    { return f1(f2(x)); };
}

int main(void)
{
    //test compose given
    auto oo = [](auto i)
    { return i + 1; };
    auto pp = [](auto i)
    { return i * 2; };
    auto oopp = compose(oo, pp);
    std::cout << oopp(5) << '\n'; // returns 11

    auto comp_lamb = [](auto f1, auto f2)
    { return [&](auto x)
      { return f1(f2(x)); }; };

    auto div4 = [](auto x)
    { return x / 4; };
    auto oopp_div4 = compose(div4, oopp);

    //shell and test given
    auto size = [](size_t x)
    { return [x](auto S)
      { return S.size() == x; }; };
    auto size5 = size(5);
    auto test = size5(string("arjun"));

    //shell and test given
    auto startsWith = [](char c)
    { return [c](string str)
      { return str.front() == c; }; };
    auto startsWithJ = startsWith('j');
    test = startsWithJ(string("joe"));

    //shell and test given
    auto endsWith = [](char c)
    { return [c](string str)
      { return str.back() == c; }; };
    auto endsWithD = endsWith('d');
    test = endsWithD(string("toad"));

    //shell and test given
    auto bool_and = [](auto f1, auto f2)
    { return [=](auto para)
      { return f1(para) && f2(para); }; };
    auto d_and_6 = bool_and(startsWith('d'), size(6));
    test = d_and_6(string("dennis"));
    // "dennis" starts with a 'd' and is 6 chars long

    auto test_5_j_d = bool_and(size(5), bool_and(startsWith('j'), endsWith('d')));
    //test given
    vector<string> vs = {"dennis", "arjun", "jared"};
    for (auto &s : vs)
        if (test_5_j_d(s))
            cout << s << '\n';

    return 0;
}