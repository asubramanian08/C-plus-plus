#include <string>
#include "csv_classes.hpp"
using namespace std;

date::date() : day(0), month(0), year(0) {}

date::date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y) {}

date::date(const string &dat)
{
    size_t ds = 0, ms = dat.find('/', ds) + 1, ys = dat.find('/', ms) + 1;
    day = stoi(dat.substr(ds, ms - ds - 1));
    month = stoi(dat.substr(ms, ys - ms - 1));
    year = stoi(dat.substr(ds, dat.size() - ds));
}

int date::operator<=>(const date &d) const { return d.year != year ? d.year - year : (d.month == month ? d.day - day : d.month - month); }