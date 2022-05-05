/* Deadlock */
#include <iostream>
#include <thread>
#include <mutex>
#include "../TE2/main.cpp"
using namespace std;

// The following code block was given
// "/* + */" means added
mutex s1mut, s2mut;
string s1, s2;
#define lp 2000
void gets1s2()
{
    for (int i = 0; i < lp; i++)
    {
        cout << __func__ << '\t' << this_thread::get_id() << '\t';
        /* + */ scoped_lock g1(s1mut, s2mut);
        // lock_guard<mutex> g1(s1mut);
        cout << s1 << '\t';
        // lock_guard<mutex> g2(s2mut);
        cout << s2 << endl;
    }
}
void gets2s1()
{
    for (int i = 0; i < lp; i++)
    {
        cout << __func__ << '\t' << this_thread::get_id() << '\t';
        /* + */ scoped_lock g2(s2mut, s1mut);
        // lock_guard<mutex> g2(s2mut);
        cout << s2 << '\t';
        // lock_guard<mutex> g1(s1mut);
        cout << s1 << endl;
    }
}

int main(void)
{
    RunThreads(gets1s2, 1, false);
    RunThreads(gets2s1, 1, true);
    /* After running this the code it just halts
        One updated the program runs and exits */
}