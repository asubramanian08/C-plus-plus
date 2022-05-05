#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "../../../Timer.cpp"
using namespace std;

// given function prototype
uint32_t linearSumMe(const uint32_t *p, long size)
{
    uint32_t sum = 0;
    for (long i = 0; i < size; i++)
        sum += p[i];
    return sum;
}

uint32_t parallelSumMe(const uint32_t *p, long size, int divisions)
{
    long section = size / divisions, remainder = size - (divisions - 1) * section;
    vector<future<uint32_t>> partialSums;
    for (int i = 0; i < divisions; i++)
        partialSums.push_back(async(linearSumMe, p + i * section, i == divisions - 1 ? remainder : section));
    uint32_t sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return sum;
}

int main(void)
{
    const long arrSize = 2'000'000'000;
    uint32_t *large_arr = new uint32_t[arrSize];
    for (int i = 0; i < arrSize; i++)
        large_arr[i] = 1;
    cout << "Linear: " << TimeMe([&arrSize, large_arr]() { cout << "Sums to " << linearSumMe(large_arr, arrSize) << " taking "; }) << endl;
    cout << "Half: " << TimeMe([&arrSize, large_arr]() { cout << "Sums to " << parallelSumMe(large_arr, arrSize, 2) << " taking "; }) << endl;
    cout << "Quarter: " << TimeMe([&arrSize, large_arr]() { cout << "Sums to " << parallelSumMe(large_arr, arrSize, 4) << " taking "; }) << endl;
    /** compile with "g++ -std=c++20 -O3 main.cpp"
     * linear time: 11363
     * half time: 8731
     * quarter time: 4827 */
}