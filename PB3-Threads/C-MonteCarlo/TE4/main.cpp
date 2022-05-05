/* Probability two dice sum to seven */

#include <iostream>
#include <future>
#include <random>
#include <vector>
using namespace std;

double twoDiceSumIsSeven(uint64_t rounds)
{
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_int_distribution distrib(1, 6);
    uint64_t totalHits = 0;
    for (uint64_t i = 0; i < rounds; i++)
        totalHits += distrib(generator) + distrib(generator) == 7;
    return (double)totalHits / rounds;
}

double calcDiceSumProbability(uint64_t rounds = 16384, int threads = thread::hardware_concurrency())
{
    vector<future<double>> partialSums;
    for (int i = 0; i < threads; i++)
        partialSums.push_back(async(twoDiceSumIsSeven, rounds / threads));
    double sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return sum / threads;
}

int main(void)
{
    cout << "Probability two dice sum to seven: " << calcDiceSumProbability() << endl;
    // The probability is 0.165894 or about 1/6
    return 0;
}