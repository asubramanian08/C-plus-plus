// stonewt.cpp -- Stonewt6 methods
#include <iostream>
using std::cout;
#include "stonewt6.hpp"
// construct Stonewt6 object from double value
Stonewt6::Stonewt6(double lbs)
{
    stone = int(lbs) / stn_wt; // integer division
    pds_left = int(lbs) % stn_wt + lbs - int(lbs);
    pounds = lbs;
}
// construct Stonewt object from stone, double values
Stonewt6::Stonewt6(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * stn_wt + lbs;
}
Stonewt6::Stonewt6() // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}
Stonewt6::~Stonewt6() // destructor
{
}
bool Stonewt6::operator>(const Stonewt6 &s) const
{
    return pounds > s.pounds;
}
bool Stonewt6::operator<(const Stonewt6 &s) const
{
    return pounds < s.pounds;
}
bool Stonewt6::operator==(const Stonewt6 &s) const
{
    return pounds == s.pounds;
}
bool Stonewt6::operator!=(const Stonewt6 &s) const
{
    return pounds != s.pounds;
}
bool Stonewt6::operator>=(const Stonewt6 &s) const
{
    return pounds >= s.pounds;
}
bool Stonewt6::operator<=(const Stonewt6 &s) const
{
    return pounds <= s.pounds;
}