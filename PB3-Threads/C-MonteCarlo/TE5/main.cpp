/** Determine if its more likely to make three free-throws or one 3-pointer
 * Comparing players Precious Achiuwa vs. Stefen Curry
 * Achiuwa: 59.0% with free-throws and 36.1% with 3-pointers
 * Curry  : 92.0% with free-throws and 38.0% with 3-pointers */

#include <iostream>
#include <future>
#include <random>
#include <vector>
using namespace std;

double freeThrows(uint64_t rounds, bool isCurry)
{
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_real_distribution<double> distrib(0, 1.0);
    uint64_t totalHits = 0;
    for (uint64_t i = 0; i < rounds; i++)
    {
        bool makesThrows = true;
        for (int j = 0; j < 3; j++)
            if (distrib(generator) > (isCurry ? 0.92 : 0.59))
                makesThrows = false;
        totalHits += makesThrows;
    }
    return (double)totalHits / rounds;
}

double threePointers(uint64_t rounds, bool isCurry)
{
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_real_distribution<double> distrib(0, 1.0);
    uint64_t totalHits = 0;
    for (uint64_t i = 0; i < rounds; i++)
        totalHits += distrib(generator) < (isCurry ? 0.380 : 0.361);
    return (double)totalHits / rounds;
}

double calcProbability(bool isFreeThrow, bool isCurry, uint64_t rounds = 16384,
                       int threads = thread::hardware_concurrency())
{
    vector<future<double>> partialSums;
    for (int i = 0; i < threads; i++)
        partialSums.push_back(async(isFreeThrow ? freeThrows : threePointers, rounds / threads, isCurry));
    double sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return sum / threads;
}

int main(void)
{
    cout << "Probability Stefen Curry     makes three free throws: " << calcProbability(true, true) << endl;
    cout << "Probability Stefen Curry     makes a three pointer  : " << calcProbability(false, true) << endl;
    // Stefen Curry has a better change making three free throws: 0.775269 > 0.384521
    cout << "Probability Precious Achiuwa makes three free throws: " << calcProbability(true, false) << endl;
    cout << "Probability Precious Achiuwa makes a three pointer  : " << calcProbability(false, false) << endl;
    // Precious Achiuwa has a better change making a three pointer: 0.207458 < 0.367065
    return 0;
}