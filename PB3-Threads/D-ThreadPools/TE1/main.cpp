#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include "../../A-Introduction/TE2/main.cpp"
#include "../../B-Promises/TE4/main.cpp"
using namespace std;

class thread_pool
{
private:
    threadsafe_queue<packaged_task<void()>> tasks;
    vector<thread> workers;

    void worker()
    {
        while (true)
        {
            unique_ptr<packaged_task<void()>> ref = move(tasks.wait_and_pop());
            if (!ref) continue;
            move (*ref.release())();
        }
    }

public:
    thread_pool(int thread_ct = thread::hardware_concurrency())
    {
        for (int i = 0; i < thread_ct; i++)
        {
            thread t([this](){worker();});
            t.detach(); 
            // workers.push_back(t);
        }
    }
    template <typename F, typename R = result_of_t<F()>>
    future<R> addTask(F task)
    {
        packaged_task<R()> pack(task);
        future<R> fut = pack.get_future();
        tasks.push(move(pack));
        // HELP: Wrapper packaged task
        return fut;
    }
};