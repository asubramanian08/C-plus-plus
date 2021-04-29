#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_if(vi.begin(), vi.end(), [](int x) { return x % 3 != 0; }), vi.end();

    cout << "Enter a sentence: ";
    istream_iterator<string> in_str(cin);
    vector<string> vs;
    //???
    vs.erase(remove_if(vs.begin(), vs.end(), [](const string &str) { return str.size() > 4; }), vs.end());
    for (const string &str : vs)
        cout << str << ' ';
    cout << endl;

    cout << "Enter a string: ";
    string noSpace;
    getline(cin, noSpace);
    noSpace.erase(remove_if(noSpace.begin(), noSpace.end(), [](char ch) { return isspace(ch) == 0; }));

    vector<int> vi_3divs;
    remove_copy_if(vi.begin(), vi.end(), back_inserter(vi_3divs), [](int x) { return x % 3 == 0; });

    return 0;
}