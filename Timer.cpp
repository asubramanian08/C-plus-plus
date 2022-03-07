#include <chrono>
using namespace std;

template <typename Time = chrono::milliseconds>
class Timer
{
private:
    chrono::steady_clock::time_point start;

public:
    Timer() { start = chrono::high_resolution_clock::now(); }
    auto elapsed() { return chrono::duration_cast<Time>(chrono::high_resolution_clock::now() - start).count(); }
    void restart() { start = chrono::high_resolution_clock::now(); }
};

// From Ch16-STL/TimeMe.cpp
template <typename Time = chrono::milliseconds, typename Func>
auto TimeMe(Func toTime)
{
    auto start = chrono::high_resolution_clock::now();
    toTime();
    auto stop = chrono::high_resolution_clock::now();
    return chrono::duration_cast<Time>(stop - start).count();
}