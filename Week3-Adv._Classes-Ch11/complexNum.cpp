//showing complex method's code
#include <iostream>
using namespace std;
#include "complexNum.hpp"
complex::complex(double r, double i)
{
    real = r;
    imaginary = i;
}
complex::complex()
{
    real = imaginary = 0;
}
complex::~complex()
{
}
complex complex::operator+(complex &c) const
{
    return complex(real + c.real, imaginary + c.imaginary);
}
complex complex::operator-(complex &c) const
{
    return complex(real - c.real, imaginary - c.imaginary);
}
complex complex::operator~() const
{
    return complex(real, -imaginary);
}
complex complex::operator*(complex &c) const
{
    return complex((real * c.real) - (imaginary * c.imaginary), (real * c.imaginary) + (imaginary * c.real));
}
complex complex::operator*(double r) const
{
    return complex(real * r, imaginary * r);
}
complex operator*(double r, complex &c)
{
    return c * r;
}
std::ostream &operator<<(std::ostream &os, const complex &c)
{
    os << '(' << c.real << ", " << c.imaginary << "i)";
    return os;
}
std::istream &operator>>(std::istream &is, complex &c)
{
    cout << "Real: ";
    is >> c.real;
    cout << "Imaginary: ";
    is >> c.imaginary;
    return is;
}