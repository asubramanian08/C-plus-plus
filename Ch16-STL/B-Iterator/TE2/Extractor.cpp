#include "Extractor.h"

Extractor::Extractor(const string &remove) : remove(remove) {}
void Extractor::extract(const string &str)
{
    newStr.clear();
    for (auto ch : str)
    {
        newStr += ch;
        if (newStr.size() < remove.size())
            continue;
        if (equal(newStr.end() - remove.size(), newStr.end(), remove.begin(), remove.end()))
            newStr.erase(newStr.size() - remove.size());
    }
}
ostream &operator<<(ostream &os, const Extractor &e)
{
    return os << e.newStr;
}