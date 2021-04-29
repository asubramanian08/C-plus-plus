#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Func>
auto TimeMe(Func toTime)
{
    auto start = chrono::high_resolution_clock::now();
    toTime();
    auto stop = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(stop - start).count();
}

int main(void)
{
    //his test
    auto len = 2 * 1E4; // 2 * 10000 = 20000
    vector<int> vi;
    // I want to time how long it takes to fill the vector
    // with the value 42. So I make a lambda function that calls fill_n
    // and pass that lambda to TimeMe.
    const auto duration = TimeMe([&vi, len]() { fill_n(back_inserter(vi), len, 42); });
    cout << "Fill took " << duration << " milliseconds\n";
    return 0;
}