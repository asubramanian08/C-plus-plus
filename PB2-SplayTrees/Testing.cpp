#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <vector>
#include "SplayMap.hpp"
#include "../Timer.cpp"
using namespace std;

ostream &operator<<(ostream &os, const pair<int, int> &p) { return os << '(' << p.first << ',' << p.second << ')'; }
void accuracy(void)
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
    }
    cout << "size(): " << accuracy.size() << endl;
    cout << "Ranged for loop though SplayMap: " << endl;
    for (auto &item : accuracy)
        cout << item << endl;
    cout << "*find(26): " << *accuracy.find(26) << endl;
    cout << "*lower_bound(26): " << *accuracy.lower_bound(26) << endl;
    cout << "*upper_bound(26): " << *accuracy.upper_bound(26) << endl;
    cout << "erase(26): " << accuracy.erase(26) << endl;
    cout << "*find(26): ";
    auto find26 = accuracy.find(26);
    if (find26 != accuracy.end())
        cout << accuracy.find(26)->second << endl;
    else
        cout << "returned end()" << endl;
    cout << "size(): " << accuracy.size() << endl;
    cout << "insert(8,-5)" << endl;
    accuracy.insert(8, -5);
    cout << "*lower_bound(7): " << *accuracy.lower_bound(7) << endl;
    cout << "*upper_bound(8): " << *accuracy.upper_bound(8) << endl;
    cout << "contains(8): " << (accuracy.contains(8) ? "true" : "false") << endl;
    cout << "clear()" << endl;
    accuracy.clear();
    cout << "empty(): " << (accuracy.empty() ? "true" : "false") << endl;
}

void efficiency(void)
{
    cout << "SPLAY MAP EFFICIENCY TESTING" << endl;
    random_device rd;
    mt19937 gen(rd());
    int totalCt, highFreq, searchCt;
    cout << "Enter the number of total values: " << flush;
    cin >> totalCt;
    cout << "Enter the number of high frequency values: " << flush;
    cin >> highFreq;
    highFreq = min(highFreq, totalCt);
    cout << "Enter the number for times to search those high frequency values: " << flush;
    cin >> searchCt;
    cout << "Generating and shuffling the key and value pairs" << endl;
    pair<int, int> *values = new pair<int, int>[totalCt];
    uniform_int_distribution randNum;
    for (int i = 0; i < totalCt; i++)
    {
        values[i] = pair(i, randNum(gen));
        swap(values[i], values[uniform_int_distribution(0, i)(gen)]);
    }
    cout << "Creating the map, SplayMap, and Timer" << endl;
    map<int, int> m;
    SplayMap sm;
    Timer t;
    cout << "Inserting " << totalCt << " values to a std map takes: ";
    t.restart();
    for (int i = 0; i < totalCt; i++)
        m[values[i].first] = values[i].second;
    cout << t.elapsed() << " milliseconds" << endl;
    cout << "Inserting " << totalCt << " values to a SplayMap takes: ";
    t.restart();
    for (int i = 0; i < totalCt; i++)
        sm[values[i].first] = values[i].second;
    cout << t.elapsed() << " milliseconds" << endl;
    cout << "Generating search order" << endl;
    for (int i = 1; i < totalCt; i++)
        swap(values[i], values[uniform_int_distribution(0, i)(gen)]);
    uniform_int_distribution highFreqGen(0, highFreq - 1);
    int *searchOrder = new int[searchCt];
    for (int i = 0; i < searchCt; i++)
        searchOrder[i] = highFreqGen(gen);
    cout << "Searching " << highFreq << " numbers " << searchCt << " times with a std map takes: ";
    t.restart();
    for (int i = 0; i < searchCt; i++)
        m.find(values[searchOrder[i]].first);
    cout << t.elapsed() << " milliseconds" << endl;
    cout << "Searching " << highFreq << " numbers " << searchCt << " times with a SplayMap takes: ";
    t.restart();
    for (int i = 0; i < searchCt; i++)
        sm.find(values[searchOrder[i]].first);
    cout << t.elapsed() << " milliseconds" << endl;
    cout << "Deleting arrays" << endl;
    delete[] values;
    delete[] searchOrder;
}

int main(void)
{
    accuracy();
    efficiency();
    return 0;
}