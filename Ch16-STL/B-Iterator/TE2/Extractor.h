#include <ostream>
#include <string>
#include <algorithm>
using namespace std;

class Extractor
{
private:
    string remove, newStr;
    static constexpr auto maxSize = string::npos;

public:
    Extractor(const string &remove);
    void extract(const string &str);
    friend ostream &operator<<(ostream &os, const Extractor &e);
};