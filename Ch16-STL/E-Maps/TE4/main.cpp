#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(void)
{
    // this section given
    multimap<string, int> test;
    test.insert({{"Ken", 42},
                 {"Dhruva", 21},
                 {"Darshan", 31},
                 {"Ken", 19},
                 {"Dhruva", 10},
                 {"Darshan", 5},
                 {"Ken", 5}});

    //print ken's scores
    auto scores = test.equal_range("Ken");
    cout << "Ken's scores:";
    for (auto ken = scores.first; ken != scores.second; ken++)
        cout << ' ' << ken->second;
    cout << endl;

    //vector of unique keys
    vector<string> keys;
    unique_copy(test.begin(), test.end(), back_inserter(keys));

    //score of each person
    cout << "Everyone's cumulative score: " << endl;
    for (auto student : keys)
    {
        scores = test.equal_range(student);
        int c_score = 0;
        for (auto grade = scores.first; grade != scores.second; grade++)
            c_score += grade->second;
        cout << student << ' ' << c_score << endl;
    }
    cout << endl;

    //names greater than 20
    cout << "Names of people greater than 20:";
    for (auto person : test)
        if (person.second > 20)
            cout << ' ' << person.first;
    cout << endl;

    return 0;
}