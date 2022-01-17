#include <iostream>

template <typename T, typename... Args>
long double sum_values(T arg1, Args... args)
{
    long double sum = arg1;
    sum += sum_values(args);
    return sum;
}
long double sum_values(void) { return 0.0; }

int main(void)
{
    std::cout << sum_values('a', 9, 23.57, 4 / 3, 'S') << std::endl;
    return 0;
}