#include <iostream>

template <typename T>
long double sum_values(T arg) { return arg; }
template <typename T, typename... Args>
long double sum_values(T arg1, Args... args) { return (long double)arg1 + sum_values(args...); }

int main(void)
{
    std::cout << sum_values('a', 9, 23.57, 4 / 3, 'S') << std::endl;
    return 0;
}