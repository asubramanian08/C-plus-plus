#include <string>
#include <set>
#include <iostream>
#include <functional>
using namespace std;

class caseInsensitiveFunctor
{
public:
    bool operator()(const string &s1, const string &s2)
    {
        return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), [](char ch1, char ch2)
                                       { return tolower(ch1) < tolower(ch2); });
    }
};

int main(void)
{
    //initializer list code given
    initializer_list<std::string> init_list = {"joe", "dennis", "jared", "markkos", "Mary", "farthington", "knucklehead", "albert", "zeelee"};
    set<string> funnyNames(init_list);
    cout << "Funny Names (normal set)" << endl;
    for (auto name : funnyNames)
        cout << name << endl;
    cout << endl;
    set<string, greater<string>> funnyNames_rsorted(funnyNames.begin(), funnyNames.end());
    set<string, caseInsensitiveFunctor> funnynames_sorted_case_insensitive(funnyNames.begin(), funnyNames.end());
    // lambda ? -> typeof
    auto caseInsensitiveLambda = [](const string &s1, const string &s2)
    {
        return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), [](char ch1, char ch2)
                                       { return tolower(ch1) < tolower(ch2); });
    };
    set<string, typeof(caseInsensitiveLambda)> funnynames_sorted_case_insensitive_lambda(funnyNames.begin(), funnyNames.end(), caseInsensitiveLambda);
    set<string> subsetFunny(funnyNames.lower_bound("farthington"), funnyNames.lower_bound("markkos"));
    set<string> missing_one_funny(funnyNames.begin(), --funnyNames.end()); //lol
    return 0;
}