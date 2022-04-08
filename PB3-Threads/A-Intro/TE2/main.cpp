#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// Given function prototype
template <typename Function>
void RunThreads(Function f, unsigned numthreads = thread::hardware_concurrency(), bool join = true)
{
    vector<thread> threads;
    for (int i = 0; i < numthreads; i++)
        threads.emplace_back(f);
    for (auto &t : threads)
        join ? t.join() : t.detach();
}

/*int main(void)
{
    auto tFunc = [](void)
    { cout << "I am a thread" << endl; };
    RunThreads(tFunc);
    RunThreads(tFunc, 12, false);
    return 0;
}*/