#include "cow.hpp"
#include <cstring>
#include <iostream>

Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}
Cow::Cow(const char *nm, const char *ho, double wt)
{
    int ho_size = strlen(ho) + 1;
    hobby = new char[ho_size];
    strncpy(hobby, ho, ho_size);
    strncpy(name, nm, 20);
    weight = wt;
}
Cow::Cow(const Cow &c)
{
    int ho_size = strlen(c.hobby) + 1;
    hobby = new char[ho_size];
    strncpy(hobby, c.hobby, ho_size);
    strncpy(name, c.name, 20);
    weight = c.weight;
}
Cow::~Cow()
{
    delete[] hobby;
}

Cow &Cow::operator=(const Cow &c)
{
    if (this != &c)
    {
        delete[] hobby; //don't have to delete if smaller
        int ho_size = strlen(c.hobby) + 1;
        hobby = new char[ho_size];
        strncpy(hobby, c.hobby, ho_size);
        strncpy(name, c.name, 20);
        weight = c.weight;
    }
    return *this;
}

void Cow::ShowCow() const
{
    using std::cout;
    using std::endl;
    cout << "The cows name is: " << name << endl
         << name << "\'s hobby is: " << hobby << endl
         << name << " weighs " << weight << " pounds" << endl;
}