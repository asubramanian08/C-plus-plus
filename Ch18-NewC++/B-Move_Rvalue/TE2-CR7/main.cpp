/**Mostly their code:
 * Made the ad2 lambda
 * Removed Adder class
 * replaced some Adder calls
 * Removed = commented out */
#include <iostream>
#include <array>
const int Size = 5;
template <typename T>
void sum(std::array<double, Size> a, T &fp);
/*class Adder
{
    double tot;

public:
    Adder(double q = 0) : tot(q) {}
    void operator()(double w) { tot += w; }
    double tot_v() const { return tot; };
};*/
int main()
{
    double total = 0.0;
    auto ad2 = [&total](double w) mutable
    { total += w; }; // Adder ad(total);
    std::array<double, Size>
        temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    sum(temp_c, /*ad*/ ad2);
    // total = ad.tot_v();
    std::cout << "total: " << /*ad.tot_v()*/ total << '\n';
    return 0;
}
template <typename T>
void sum(std::array<double, Size> a, T &fp)
{
    for (auto pt = a.begin(); pt != a.end(); ++pt)
    {
        fp(*pt);
    }
}