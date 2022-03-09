#include <iostream>
#include <future>
#include <thread>
#include "../../../Timer.cpp"
using namespace std;

// given function prototype
int64_t linearSumMe(const int *p, long size)
{
    int64_t sum = 0;
    for (long i = 0; i < size; i++)
        sum += p[i];
    return sum;
}

int64_t partialSumMe(const int *p, long size, int divisions)
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
    int *large_arr = new int[arrSize];
    // correct way to give function?
    long long linearTime = TimeMe([&arrSize, large_arr]()
                                  { linearSumMe(large_arr, arrSize); });
    long long halfTime = TimeMe([&arrSize, large_arr]()
                                { partialSumMe(large_arr, arrSize, 2); });
    long long quarterTime = TimeMe([&arrSize, large_arr]()
                                   { partialSumMe(large_arr, arrSize, 4); });
    cout << "linear time: " << linearTime << endl
         << "half time: " << halfTime << endl
         << "quarter time: " << quarterTime << endl;
    // Its actually fairly similar with the all methods?
}