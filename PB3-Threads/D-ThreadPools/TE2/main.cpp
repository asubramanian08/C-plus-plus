#include <iostream>
#include <functional>
#include "../TE1/main.cpp"
using namespace std;

bool isPrime(int64_t num)
{
    cout << "\t\t\t" << this_thread::get_id() << " processing " << num << endl;
    for (int64_t i = 2; i < num; i++)
        if (num % i == 0)
        {
            cout << "\t\t\t" << this_thread::get_id() << '\t' << num << " is NOT prime" << endl;
            return false;
        }
    cout << "\t\t\t" << this_thread::get_id() << '\t' << num << " is prime" << endl;
    return true;
}

int main(void)
{
    thread_pool pool;
    while (true)
    {
        int64_t val;
        cout << "Enter a prime:  " << endl;
        cin >> val;
        if (!val)
            break;
        auto f = pool.addTask(bind(isPrime, val));
        // HELP: should I forget about f?
    }
}