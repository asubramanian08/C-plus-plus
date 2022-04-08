#include <iostream>
#include <future>
#include <thread>
#include "../../../Timer.cpp"
using namespace std;

// given function prototype
int64_t linearSumMe(const long long *p, long size)
{
    int64_t sum = 0;
    for (long i = 0; i < size; i++)
        sum += p[i];
    return sum;
}

int64_t parallelSumMe(const long long *p, long size, int divisions)
{
    long section = size / divisions, remainder = size - (divisions - 1) * section;
    int64_t sum = 0;
    for (int i = 0; i < divisions; i++)
        sum += async(linearSumMe, p + i * section, i == divisions - 1 ? remainder : section).get();
    return sum;
}

int main(void)
{
    const long arrSize = 1'000'000'000;
    long long *large_arr = new long long[arrSize];
    for (int i = 0; i < arrSize; i++)
        large_arr[i] = 1;
    long long linearTime = TimeMe([&arrSize, large_arr]()
                                  { linearSumMe(large_arr, arrSize); });
    long long halfTime = TimeMe([&arrSize, large_arr]()
                                { parallelSumMe(large_arr, arrSize, 2); });
    long long quarterTime = TimeMe([&arrSize, large_arr]()
                                   { parallelSumMe(large_arr, arrSize, 4); });
    cout << "linear time: " << linearTime << endl
         << "half time: " << halfTime << endl
         << "quarter time: " << quarterTime << endl;
    // Fairly similar times: caching
    /** Using long long's instead of ints
     * linear time: 32171
     * half time: 12936
     * quarter time: 12991 */
}