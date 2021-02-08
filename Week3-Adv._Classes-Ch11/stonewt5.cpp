//NOTE: see who did what work in header
// stonewt.cpp -- Stonewt5 methods
#include <iostream>
using std::cout;
#include "stonewt5.hpp"
// construct Stonewt5 object from double value
Stonewt5::Stonewt5(double lbs, ioForm m)
{
    stone = int(lbs) / stn_wt; // integer division
    pds_left = int(lbs) % stn_wt + lbs - int(lbs);
    pounds = lbs;
    mode = m;
}
// construct Stonewt5 object from stone, double values
Stonewt5::Stonewt5(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * stn_wt + lbs;
    mode = STONE;
}
Stonewt5::Stonewt5(ioForm m) // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = m;
}
Stonewt5::~Stonewt5() // destructor
{
}
void Stonewt5::setMode(ioForm m)
{
    mode = m;
}
std::ostream &operator<<(std::ostream &os, const Stonewt5 &s)
{
    if (s.mode == Stonewt5::STONE)
        os << s.stone << " stone, " << s.pds_left << " pounds" << std::endl;
    else if (s.mode == Stonewt5::DOUB_LBS)
        os << s.pounds << " pounds" << std::endl;
    else if (s.mode == Stonewt5::INT_LBS)
        os << int(s.pounds + 0.5) << "rounded pounds" << std::endl;
    else
        os << "Invalid mode" << std::endl;
    return os;
}
Stonewt5 Stonewt5::operator+(const Stonewt5 &s) const
{
    Stonewt5 sum(pounds + s.pounds);
    sum.setMode(mode);
    return sum;
}
Stonewt5 Stonewt5::operator-(const Stonewt5 &s) const
{
    Stonewt5 sum(pounds - s.pounds);
    sum.setMode(mode);
    return sum;
}
Stonewt5 Stonewt5::operator*(double mult) const
{
    Stonewt5 sum(pounds * mult);
    sum.setMode(mode);
    return sum;
}
Stonewt5 operator*(double mult, const Stonewt5 &s)
{
    return s * mult;
}