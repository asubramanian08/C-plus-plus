#include <chrono>
//made in Lambda TE6
template <typename Func>
auto TimeMe(Func toTime)
{
    auto start = chrono::high_resolution_clock::now();
    toTime();
    auto stop = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(stop - start).count();
}