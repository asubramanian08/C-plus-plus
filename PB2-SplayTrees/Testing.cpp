#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <vector>
#include "SplayMap.hpp"
#include "TemplateSplayMap.hpp"
#include "../Timer.cpp"
using namespace std;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ',' << p.second << ')'; }

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
    cout << "Ranged for loop though SplayMap:" << endl;
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
    cout << endl;
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
    cout << endl;
}

void constantTemplateMethods(const TmpSplayMap<string, int> &tsm)
{
    cout << "CONSTANT TEMPLATE SPLAY MAP METHOD TESTING" << endl;
    cout << "operator[](\"sailor\"): " << tsm["sailor"] << endl;
    cout << "operator[](\"chair\"): ";
    try
    {
        cout << tsm["chair"] << endl;
    }
    catch (...)
    {
        cout << "exception thrown" << endl;
    }
    cout << "size(): " << tsm.size() << endl;
    cout << "Ranged for loop though SplayMap:" << endl;
    for (const auto &kv : tsm)
        cout << kv << endl;
    cout << "*cbegin(): " << *tsm.cbegin() << endl;
    cout << "contains(\"hi\"): " << (tsm.contains("hi") ? "true" : "false") << endl;
    cout << "contains(\"walrus\"): " << (tsm.contains("walrus") ? "true" : "false") << endl;
    cout << "*find(\"hamburger\"): " << *tsm.find("hamburger") << endl;
    cout << "*upper_bound(\"jones\"): " << *tsm.upper_bound("jones") << endl;
    cout << "*lower_bound(\"jones\"): " << *tsm.lower_bound("jones") << endl;
    cout << "empty(): " << (tsm.empty() ? "true" : "false") << endl;
}

void templateAccuracy(void)
{
    cout << "TEMPLATE SPLAY MAP ACCURACY TESTING" << endl;
    cout << "TmpSplayMap<string, int>()" << endl;
    TmpSplayMap<string, int> tsm;
    cout << "empty(): " << (tsm.empty() ? "true" : "false") << endl;
    cout << "operator[](\"hi\"): " << tsm["hi"] << endl;
    cout << "size(): " << tsm.size() << endl;
    cout << "*begin(): " << *tsm.begin() << endl;
    cout << "insert(\"bye\", 42)" << endl;
    tsm.insert("bye", 42);
    cout << "*upper_bound(\"b\"): " << *tsm.upper_bound("b") << endl;
    cout << "*lower_bound(\"b\"): " << *tsm.lower_bound("b") << endl;
    cout << "erase(\"b\"): " << tsm.erase("b") << endl;
    cout << "contains(\"hi\"): " << (tsm.contains("hi") ? "true" : "false") << endl;
    cout << "erase(\"hi\"): " << tsm.erase("hi") << endl;
    cout << "contains(\"hi\"): " << (tsm.contains("hi") ? "true" : "false") << endl;
    cout << "size(): " << tsm.size() << endl;
    cout << "clear()" << endl;
    tsm.clear();
    cout << "empty(): " << (tsm.empty() ? "true" : "false") << endl;
    string insOrder[] = {"jones", "walrus", "water", "hamburger", "waiter", "sailor", "abracadabra"};
    for (int i = 0; i < 7; i++)
    {
        int v = ((insOrder[i][0] + 17) << 2) ^ ((i * 43) >> 3);
        cout << "insert" << make_pair(insOrder[i], v) << endl;
        tsm.insert(insOrder[i], v);
    }
    cout << "size(): " << tsm.size() << endl;
    cout << "Ranged for loop though SplayMap:" << endl;
    for (auto &kv : tsm)
        cout << kv << endl;
    cout << "*find(\"waiters\"): ";
    auto findWaiters = tsm.find("waiters");
    if (findWaiters == tsm.end())
        cout << "end()" << endl;
    else // valid result
        cout << *findWaiters << endl;
    cout << "*find(\"waiter\"): " << *tsm.find("waiter") << endl;
    constantTemplateMethods(tsm);
    cout << endl;
}

int main(void)
{
    accuracy();
    efficiency();
    templateAccuracy();
    return 0;
}