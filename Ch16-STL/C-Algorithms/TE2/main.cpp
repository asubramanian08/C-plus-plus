#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;

int main(void)
{
    vector<string> animals = {"dog", "cat", "bear", "frog", "aardvark", "canary"};
    ostream_iterator<string> out_str(cout, " ");
    copy(animals.begin(), animals.end(), out_str);
    cout << endl;
    copy_if(animals.begin(), animals.end(), out_str, [](string str) { return str.size() > 3; });
    cout << endl;
    transform(animals.begin(), animals.end(), out_str, [](string str) {
        if (!str.empty())
            str[0] = toupper(str[0]);
        return str;
    });
    cout << endl;
    return 0;
}