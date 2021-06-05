#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    map<string, unsigned int> pop = {make_pair("China", 1'439'323'776),
                                     make_pair("India", 1'380'004'385),
                                     make_pair("USA", 331'002'651),
                                     make_pair("Tokelau", 1'411)};
    for (auto country : pop)
        cout << country.first << ' ' << country.second << endl;
    //sorted by the key in assending order
    cout << "The population of Tokelau is: " << pop["Tokelau"] << endl;
    cout << "The population of Japan (wasn't added) is: " << pop["Japan"] << endl;
    //It returns 0, the map now has 5 elements
    pop.find("Japan")->second = 125'961'625;
    pop["Argentina"] = 45'195'774;
    cout << "The population of India is: " << pop.at("India") << endl;
    try
    {
        cout << "The population of Brazil (wasn't added) is: " << pop.at("Brazil") << endl;
    }
    catch (out_of_range &e)
    {
        cout << e.what() << endl;
    }
    //an out_or_range expection is thrown, you can put at in a try catch block (I did that above)
    //at() doesn't add a new element when a key isn't there, it throws an exception
    pop["Mars"] = 42;
    pop.erase("Mars");
    pop.insert(make_pair("Russia", 145'934'462));
    pop.insert({
        {"Ghana", 31'072'940},
        {"Myanmar", 54'409'800},
        {"Spain", 46'754'778},
    });
    pop.emplace("France", 65'273'511);
    auto strCmp = [](const string &str1, const string &str2)
    { return str1 > str2; };
    map<string, unsigned int, decltype(strCmp)> rPop(strCmp);
    rPop.insert(pop.begin(), pop.end());
    cout << "rPop's values:";
    for (auto country : rPop)
        cout << ' ' << country.second;
    cout << endl;
    pop.erase(pop.lower_bound("Myanmar"), pop.upper_bound("USA"));
    return 0;
}