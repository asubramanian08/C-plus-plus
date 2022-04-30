// Exercise one was changed!
#include <execution>
#include <iostream>
#include <numeric>
#include "../../../Timer.cpp"
using namespace std;

int main(void)
{
    const long arrSize = 2'000'000'000;
    uint32_t *large_arr = new uint32_t[arrSize];
    for (int i = 0; i < arrSize; i++)
        large_arr[i] = 1;
    DisplayTime([&arrSize, large_arr]() { return reduce(execution::seq, large_arr, large_arr + arrSize); }, "Sequenced");
    DisplayTime([&arrSize, large_arr]() { return reduce(execution::par, large_arr, large_arr + arrSize); }, "Parallel");
    DisplayTime([&arrSize, large_arr]() { return reduce(execution::unseq, large_arr, large_arr + arrSize); }, "Unsequenced");
    DisplayTime([&arrSize, large_arr]() { return reduce(execution::par_unseq, large_arr, large_arr + arrSize); }, "Parallel Unsequenced");
    // Doesn't compile: mac compiler doesn't properly include execution
}