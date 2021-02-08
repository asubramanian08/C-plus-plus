//NOTE: majority not mine
// stonewt.h -- definition for the Stonewt5 class
#ifndef STONEWT_H_5
#define STONEWT_H_5
class Stonewt5
{
public:
    enum ioForm
    {
        STONE,
        INT_LBS,
        DOUB_LBS
    };

private:
    static const int stn_wt = 14; // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    ioForm mode;                  // diplay form

public:
    Stonewt5(double lbs, ioForm m = DOUB_LBS); // constructor for double pounds
    Stonewt5(int stn, double lbs);             // constructor for stone, lbs
    Stonewt5(ioForm m = STONE);                // default constructor
    ~Stonewt5();
    void setMode(ioForm m);
    friend std::ostream &operator<<(std::ostream &os, const Stonewt5 &s);
    Stonewt5 operator+(const Stonewt5 &s) const;
    Stonewt5 operator-(const Stonewt5 &s) const;
    Stonewt5 operator*(double mult) const;
    friend Stonewt5 operator*(double mult, const Stonewt5 &s);
};
#endif