/* Race conditions */
#include <thread>
#include <stack>
#include <mutex>
#include "../TE2/main.cpp"
using namespace std;

// Given the following code block
std::stack<int> s;
void race_ya()
{
    while (!s.empty())
    {
        this_thread::yield();
        int const value = s.top();
        this_thread::yield();
        s.pop();
    }
}

mutex stk_mtx;
void safe_race()
{
    lock_guard<mutex> lg(stk_mtx);
    while (!s.empty())
    {
        this_thread::yield();
        int const value = s.top();
        this_thread::yield();
        s.pop();
    }
}

int main(void)
{
    s.push(5);
    s.push(2);
    s.push(13);
    s.push(-2);
    s.push(6);
    // RunThreads(race_ya);
    RunThreads(safe_race);
}