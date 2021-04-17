#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;

int main(void)
{
    vector<string> animals = {"dog", "cat", " bear ", " frog ", " aardvark ", "canary"};
    ostream_iterator<int> out_str(cout, " ");
    copy(animals.begin(), animals.end(), out_str);
    copy_if(animals.begin(), animals.end(), out_str, [](string str) { return str.size() > 3; });
    return 0;
}