#include <vector>
#include <iostream>
using namespace std;

int oldFib(int x)
{
    if (x < 2)
        return 1;
    return oldFib(x - 1) + oldFib(x - 2);
}

class fibfunctor
{
private:
    vector<int> lookUp;

public:
    fibfunctor()
    {
        lookUp.push_back(1);
        lookUp.push_back(1);
    }
    int operator()(int x)
    {
        if (x >= lookUp.size()) //will always be =
            lookUp.push_back((*this)(x - 1) + (*this)(x - 2));
        return lookUp[x];
    }
};

int main(void)
{
    //his test
    fibfunctor fib; // the internal vector contains fib 0 and fib 1
    const int N = 40;
    for (int i = 0; i < N; i++)
        cout << oldFib(i) << endl;
    for (int i = 0; i < N; i++)
        cout << fib(i) << endl;
    return 0;
}