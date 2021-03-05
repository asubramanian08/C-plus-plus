#include "cd.h"
#include <cstring>
#include <iostream>
using std::cout;

const char defPref[] = "none listed";
const char defLabel[] = "no label";

Cd::Cd(const char *prfs, const char *lbl, int plays, double time)
{
    perfLen = strlen(prfs) + 1;
    performers = new char[perfLen];
    strncpy(performers, prfs, perfLen);

    labelLen = strlen(lbl) + 1;
    label = new char[labelLen];
    strncpy(label, lbl, labelLen);

    selections = plays;
    playtime = time;
}
Cd::Cd(const Cd &d)
{
    perfLen = d.perfLen;
    performers = new char[perfLen];
    strncpy(performers, d.performers, perfLen);

    labelLen = d.labelLen;
    label = new char[labelLen];
    strncpy(label, d.label, labelLen);

    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd()
{
    perfLen = strlen(defPref) + 1;
    performers = new char[perfLen];
    strncpy(performers, defPref, perfLen);

    labelLen = strlen(defLabel) + 1;
    label = new char[labelLen];
    strncpy(label, defLabel, labelLen);

    selections = 0;
    playtime = 0;
}
Cd::~Cd()
{
    delete[] performers;
    delete[] label;
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
    perfLen = d.perfLen;
    delete[] performers;
    performers = new char[perfLen];
    strncpy(performers, d.performers, perfLen);

    labelLen = d.labelLen;
    delete[] label;
    label = new char[labelLen];
    strncpy(label, d.label, labelLen);

    selections = d.selections;
    playtime = d.playtime;
    return *this;
}