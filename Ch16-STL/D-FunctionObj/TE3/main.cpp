#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> fib;
    {
        int element = -1;
        generate_n(back_inserter(fib), 20, [&]() {
            element++;
            if (element < 2)
                return element;
            return fib[element - 2] + fib[element - 1];
        });
    }
    return 0;
}