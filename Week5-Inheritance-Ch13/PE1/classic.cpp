#include "classic.h"
#include <cstring>
#include <iostream>
using std::cout;

Classic::Classic(const char *prfs, const char *lbl, const char *p_work, int plays, double time)
    : Cd::Cd(prfs, lbl, plays, time) { strncpy(primWork, p_work, WORK_MAXLEN); }
Classic::Classic(const Classic &cls) : Cd::Cd(cls)
{
    strncpy(primWork, cls.primWork, WORK_MAXLEN);
}
Classic::Classic() : Cd::Cd() { strncpy(primWork, "No primary work", WORK_MAXLEN); }
Classic::~Classic() {}

void Classic::Report() const
{
    Cd::Report();
    cout << "The primary work is: " << primWork << '\n';
}
Classic &Classic::operator=(const Classic &cls)
{
    Cd::operator=(cls);
    strncpy(primWork, cls.primWork, WORK_MAXLEN);
    return *this;
}