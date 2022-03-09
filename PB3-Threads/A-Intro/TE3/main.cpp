/* Race conditions */
#include <thread>
#include <stack>
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

void safe_race() // HELP - how to do this? Should I use mutex
{
    while (!s.empty())
    {
        int const value = s.top(); // Why is this value const?
        s.pop();
        this_thread::yield();
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