// stonewt.h -- definition for the Stonewt6 class
#ifndef STONEWT_H_6
#define STONEWT_H_6
class Stonewt6
{
private:
    static const int stn_wt = 14; // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt6(double lbs);          // constructor for double pounds
    Stonewt6(int stn, double lbs); // constructor for stone, lbs
    Stonewt6();                    // default constructor
    ~Stonewt6();
    void show_lbs() const; // show weight in pounds format
    void show_stn() const; // show weight in stone format
    friend std::ostream &operator<<(std::ostream &os, const Stonewt6 &s);
    bool operator>(const Stonewt6 &s) const;
    bool operator<(const Stonewt6 &s) const;
    bool operator==(const Stonewt6 &s) const;
    bool operator!=(const Stonewt6 &s) const;
    bool operator>=(const Stonewt6 &s) const;
    bool operator<=(const Stonewt6 &s) const;

    //int operator<=>(const Stonewt6 &s) const; //could do but didn't implement
};
#endif