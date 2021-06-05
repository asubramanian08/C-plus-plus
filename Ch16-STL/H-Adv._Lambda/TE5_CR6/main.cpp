#include <iostream>
using namespace std;

//given
template <typename T>
void show2(double x, T &fp) { std::cout << x << " -> " << fp(x) << '\n'; }

//changed to lambda
auto f1 = [](double x)
{ return 1.8 * x + 32; };

//given
int main(void)
{
    show2(18.0, f1);
    return 0;
}