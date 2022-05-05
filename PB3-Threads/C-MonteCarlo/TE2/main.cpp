/* Estimating e */

#include <iostream>
#include <future>
#include <random>
#include <vector>
using namespace std;

uint64_t count_rands_to_sum_greater_than_1(uint64_t number_tries)
{
    // copied from TE1
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_real_distribution<double> distrib(0, 1.0);

    uint64_t total_count = 0;
    for (uint64_t i = 0; i < number_tries; i++)
        for (double sum = 0.0; sum < 1.0; total_count++)
            sum += distrib(generator);
    return total_count;
}

// given function declaration
double CalcAvgRandCallsSumGreater1(int numthreads = 1, uint64_t total_number_tries = 1024)
{
    // mostly copied from TE1
    vector<future<uint64_t>> partialSums;
    for (int i = 0; i < numthreads; i++)
        partialSums.push_back(async(count_rands_to_sum_greater_than_1, total_number_tries / numthreads));
    uint64_t sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return (double)sum / total_number_tries;
}

int main(void)
{
    cout << "e approximation with 1024     tries: " << CalcAvgRandCallsSumGreater1(thread::hardware_concurrency(), 1024) << endl;
    cout << "e approximation with 8192     tries: " << CalcAvgRandCallsSumGreater1(thread::hardware_concurrency(), 8192) << endl;
    cout << "e approximation with 524288   tries: " << CalcAvgRandCallsSumGreater1(thread::hardware_concurrency(), 524288) << endl;
    cout << "e approximation with 16777216 tries: " << CalcAvgRandCallsSumGreater1(thread::hardware_concurrency(), 16777216) << endl;
    // The number we are approximating is e!
    return 0;
}