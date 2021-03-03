#include "cd.h"
#include <cstring>
#include <iostream>
using std::cout;

Cd::Cd(const char *prfs, const char *lbl, int plays, double time)
{
    strncpy(performers, prfs, PERF_LEN);
    strncpy(label, lbl, LABEL_LEN);
    selections = plays;
    playtime = time;
}
Cd::Cd(const Cd &d)
{
    strncpy(performers, d.performers, PERF_LEN);
    strncpy(label, d.label, LABEL_LEN);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd()
{
    strncpy(performers, "none listed", PERF_LEN);
    strncpy(label, "no label", LABEL_LEN);
    selections = 0;
    playtime = 0;
}
Cd::~Cd()
{
}
void Cd::Report() const
{
    cout << "The performers are: " << performers << '\n'
         << "The label is: " << label << '\n'
         << "The number of selections is " << selections << '\n'
         << "The total playtime is " << playtime << '\n';
}
Cd &Cd::operator=(const Cd &d)
{
    strncpy(performers, d.performers, PERF_LEN);
    strncpy(label, d.label, LABEL_LEN);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}