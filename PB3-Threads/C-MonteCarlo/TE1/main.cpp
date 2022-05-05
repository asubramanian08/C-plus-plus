/* Estimating Pi */

#include <iostream>
#include <cmath>
#include <future>
#include <random>
#include <vector>
#include "../../../Timer.cpp"
using namespace std;

// PART A: given the first section of code
double random_points_in_circle(uint64_t num_points)
{
    uint64_t point_in_circle = 0;
    random_device seed_gen;
    mt19937 generator(seed_gen()); // Standard mersenne_twister_engine
    uniform_real_distribution<double> distrib(0, 1.0);

    // the following is my code
    for (uint64_t i = 0; i < num_points; i++)
    {
        double rand_x = distrib(generator);
        double rand_y = distrib(generator);
        point_in_circle += sqrt(rand_x * rand_x + rand_y * rand_y) <= 1;
    }
    /** estimating pi formula:
     * quarter of unit circle: pi/4
     * area of unit square: 1^2 = 1
     * point_in_circle / num_points ≈ (pi/4)/1
     * pi ≈ 4 * point_in_circle / num_points */
    return 4.0 * point_in_circle / num_points;
}

// PART B: given function declaration
double CalcPI(int numthreads = 1, uint64_t total_number_points = 1024)
{
    vector<future<double>> partialSums;
    for (int i = 0; i < numthreads; i++)
        partialSums.push_back(async(random_points_in_circle, total_number_points / numthreads));
    double sum = 0;
    for (auto &f : partialSums)
        sum += f.get();
    return sum / numthreads;
}

// PART C: test the timing (thread count) and accuracy (points tested)
int main(void)
{
    DisplayTime([]()
                { return CalcPI(1, 16777216); },
                "Pi approximation with one   thread ");
    DisplayTime([]()
                { return CalcPI(2, 16777216); },
                "Pi approximation with two   threads");
    DisplayTime([]()
                { return CalcPI(4, 16777216); },
                "Pi approximation with four  threads");
    DisplayTime([]()
                { return CalcPI(8, 16777216); },
                "Pi approximation with eight threads");
    /** How long each version takes
     * one   thread : 3388 ms
     * two   threads: 1803 ms
     * four  threads: 1456 ms
     * eight threads: 1433 ms */
    cout << "Pi approximation with 1024     points: " << CalcPI(8, 1024) << endl;
    cout << "Pi approximation with 8192     points: " << CalcPI(8, 8192) << endl;
    cout << "Pi approximation with 524288   points: " << CalcPI(8, 524288) << endl;
    cout << "Pi approximation with 16777216 points: " << CalcPI(8, 16777216) << endl;
    /** More points increase accuracy to an extent
     * 1024     points: 3.30859
     * 8192     points: 3.16553
     * 524288   points: 3.13860
     * 16777216 points: 3.14118 */
    return 0;
}