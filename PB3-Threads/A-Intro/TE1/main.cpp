#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// Given function prototype
template <typename Function>
void RunThreads(Function f, unsigned numthreads = 0, bool join = true)
{
    vector<thread> threads;
    for (int i = 0; i < numthreads; i++)
        threads.emplace_back(f);
    for (int i = 0; i < numthreads; i++)
        join ? threads[i].join() : threads[i].detach();
}

int main(void)
{
    auto tFunc = [](void)
    { cout << "I am a thread" << endl; };
    RunThreads(tFunc);
    RunThreads(tFunc, 12, false);
    return 0;
}