// Given the main function
#include <iostream>
using namespace std;

template <typename T>
T average_list(initializer_list<T> list)
{
    T sum = 0;
    for (const T &item : list)
        sum += item;
    return sum / list.size();
}

int main()
{
    using namespace std;
    // list of double deduced from list contents
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
    // list of int deduced from list contents
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
    // forced list of double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}