#include "classic.h"
#include <cstring>
#include <iostream>
using std::cout;

const char defWork[] = "No primary work";

Classic::Classic(const char *prfs, const char *lbl, const char *p_work, int plays, double time)
    : Cd::Cd(prfs, lbl, plays, time)
{
    workLen = strlen(p_work) + 1;
    primWork = new char[workLen];
    strncpy(primWork, p_work, workLen);
}
Classic::Classic(const Classic &cls) : Cd::Cd(cls)
{
    workLen = strlen(cls.primWork) + 1;
    primWork = new char[workLen];
    strncpy(primWork, cls.primWork, workLen);
}
Classic::Classic() : Cd::Cd()
{
    workLen = strlen(defWork) + 1;
    primWork = new char[workLen];
    strncpy(primWork, defWork, workLen);
}
Classic::~Classic() { delete[] primWork; }

void Classic::Report() const
{
    Cd::Report();
    cout << "The primary work is: " << primWork << '\n';
}
Classic &Classic::operator=(const Classic &cls)
{
    Cd::operator=(cls);
    workLen = strlen(cls.primWork) + 1;
    delete[] primWork;
    primWork = new char[workLen];
    strncpy(primWork, cls.primWork, workLen);
    return *this;
}