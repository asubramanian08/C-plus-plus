/* Monty Hall problem */

#include <iostream>
#include <future>
#include <random>
#include <vector>
using namespace std;

double stayPercentage(uint64_t rounds)
{
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_int_distribution distrib(1, 3);
    uint64_t totalWins = 0;
    for (uint64_t i = 0; i < rounds; i++)
    {
        int winningDoor = distrib(generator);
        int contestentPick = distrib(generator);
        totalWins += contestentPick == winningDoor;
    }
    return 100.0 * totalWins / rounds;
}

double switchPercentage(uint64_t rounds)
{
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_int_distribution distrib(1, 3);
    uniform_int_distribution dist2(0, 1);
    uint64_t totalWins = 0;
    for (uint64_t i = 0; i < rounds; i++)
    {
        int winningDoor = distrib(generator);
        int contestentPick = distrib(generator);
        int montyShows = winningDoor % 3 + 1;
        if (montyShows == contestentPick ||                     // Would have showed contest's pick
            (contestentPick == montyShows && dist2(generator))) // Pick the other door with 1/2 prob
            montyShows = montyShows % 3 + 1;
        // make the switch: change from original pick to whatever monty didn't show
        if ((contestentPick = contestentPick % 3 + 1) == montyShows)
            contestentPick = contestentPick % 3 + 1;
        totalWins += contestentPick == winningDoor;
    }
    return 100.0 * totalWins / rounds;
}

double calcStayPercentage(uint64_t rounds = 1024, int threads = thread::hardware_concurrency())
{
    vector<future<double>> partialSums;
    for (int i = 0; i < threads; i++)
        partialSums.push_back(async(stayPercentage, rounds / threads));
    double sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return sum / threads;
}

double calcSwitchPercentage(uint64_t rounds = 16384, int threads = thread::hardware_concurrency())
{
    vector<future<double>> partialSums;
    for (int i = 0; i < threads; i++)
        partialSums.push_back(async(switchPercentage, rounds / threads));
    double sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return sum / threads;
}

int main(void)
{
    cout << "Percentage of times the contestant wins by staying  : " << calcStayPercentage() << endl;   // 33.0078
    cout << "Percentage of times the contestant wins by switching: " << calcSwitchPercentage() << endl; // 66.2903
    return 0;
}