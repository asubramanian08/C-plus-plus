//My work entirely
#include <iostream>
class complex
{
private:
    double real, imaginary;

public:
    //constructer and destructor
    complex(double r, double i);
    complex();
    ~complex();
    //arithmetic operator overloading
    complex operator+(complex &c) const;
    complex operator-(complex &c) const;
    complex operator~() const;
    complex operator*(complex &c) const;
    complex operator*(double r) const;
    friend complex operator*(double r, complex &c);
    //io-operator overloading
    friend std::ostream &operator<<(std::ostream &os, const complex &c);
    friend std::istream &operator>>(std::istream &is, complex &c); //cout is assumed out stream
};