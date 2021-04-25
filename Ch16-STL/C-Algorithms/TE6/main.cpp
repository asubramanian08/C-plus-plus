#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
#define SIZE 2'000'000'000
//times things
#include <chrono>

int main(void)
{
    vector<int> vi(SIZE);
    iota(vi.begin(), vi.end(), 1);

    auto start = chrono::high_resolution_clock::now();
    find(vi.begin(), vi.end(), SIZE);
    auto stop = chrono::high_resolution_clock::now();
    cout << "Find time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << endl;

    start = chrono::high_resolution_clock::now();
    binary_search(vi.begin(), vi.end(), SIZE);
    stop = chrono::high_resolution_clock::now();
    cout << "Binary search time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << endl;

    // binary search only makes log(n) compare
    // while find looks through every element
    return 0;
}