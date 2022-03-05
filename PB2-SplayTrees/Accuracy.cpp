#include <iostream>
#include <vector>
#include "SplayMap.hpp"
using namespace std;

ostream &operator<<(ostream &os, const pair<int, int> &p) { return os << '(' << p.first << ',' << p.second << ')'; }

int main(void)
{
    cout << "SPLAY MAP ACCURACY TESTING" << endl;
    cout << "SplayMap()" << endl;
    SplayMap accuracy;
    cout << "empty(): " << (accuracy.empty() ? "true" : "false") << endl;
    cout << "size(): " << accuracy.size() << endl;
    cout << "operator[](3) = 42" << endl;
    accuracy[3] = 42;
    cout << "size(): " << accuracy.size() << endl;
    cout << "at(3): ";
    try
    {
        int value = accuracy.at(3);
        cout << value << endl;
    }
    catch (...)
    {
        cout << "exception thrown" << endl;
    }
    cout << "contains(3): " << (accuracy.contains(3) ? "true" : "false") << endl;
    cout << "erase(3): " << accuracy.erase(3) << endl;
    cout << "contains(3): " << (accuracy.contains(3) ? "true" : "false") << endl;
    cout << "at(3): ";
    try
    {
        int value = accuracy.at(3);
        cout << value << endl;
    }
    catch (...)
    {
        cout << "exception thrown" << endl;
    }
    cout << "empty(): " << (accuracy.empty() ? "true" : "false") << endl;
    vector<int> insOrder = {13, 8, 2, 34, 26, 21, 78, 92, 36, 87};
    for (int i = 0; i < 10; i++)
    {
        int v = ((i + 17) << 2) ^ ((insOrder[i] * 43) >> 3);
        cout << "insert" << make_pair(insOrder[i], v) << endl;
        accuracy.insert(insOrder[i], v);
        // The lazy insert is the issue!
    }
    cout << "size(): " << accuracy.size() << endl;
    cout << "Ranged for loop though SplayMap: " << endl;
    for (auto item : accuracy)
        cout << item << endl;
    cout << "*find(7): " << *accuracy.find(7) << endl;
    cout << "*lower_bound(7): " << *accuracy.lower_bound(7) << endl;
    cout << "*upper_bound(7): " << *accuracy.upper_bound(7) << endl;
    cout << "erase(7): " << accuracy.erase(7) << endl;
    cout << "*find(7): ";
    auto find7 = accuracy.find(7);
    if (find7 != accuracy.end())
        cout << accuracy.find(7)->second << endl;
    else
        cout << "find(7) returned end()";
    cout << "insert(7,-5)" << endl;
    accuracy.insert(7, -5);
    cout << "*lower_bound(7): " << *accuracy.lower_bound(7) << endl;
    cout << "*upper_bound(7): " << *accuracy.upper_bound(7) << endl;
    cout << "contains(7): " << (accuracy.contains(7) ? "true" : "false") << endl;
    cout << "size(): " << accuracy.size() << endl;
    cout << "clear()" << endl;
    accuracy.clear();
    cout << "empty(): " << (accuracy.empty() ? "true" : "false") << endl;
}