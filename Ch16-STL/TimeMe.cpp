#include <chrono>
//made in Lambda TE6
//changed in sets TE5
template <typename Time = chrono::milliseconds, typename Func>
auto TimeMe(Func toTime)
{
    auto start = chrono::high_resolution_clock::now();
    toTime();
    auto stop = chrono::high_resolution_clock::now();
    return chrono::duration_cast<Time>(stop - start).count();
}