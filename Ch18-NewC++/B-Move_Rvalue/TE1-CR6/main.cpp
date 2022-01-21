// Mostly their code: I added f2 and changed show2 parameter
#include <iostream>
template <typename T>
void show2(double x, T &fp) { std::cout << x << " -> " << fp(x) << '\n'; }
double f1(double x) { return 1.8 * x + 32; }
int main()
{
    auto f2 = [](double x)
    { return 1.8 * x + 32; };
    show2(18.0, /*f1*/ f2);
    return 0;
}