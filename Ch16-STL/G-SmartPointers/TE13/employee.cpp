//given and added to
#include <iostream>
#include "employee.hpp"
struct employee::impl
{
    impl(const string &name, int id) : name(name), id(id) {}
    ~impl() = default;
    string name;
    int id;
    // added things
    const static int minPay = 50'000, tierMult = 10'000, yearMult = 2'000;
    int tier = 1, years = 0;
    int calc_salary() { return minPay + (tierMult * tier) + (yearMult * years); }
};
// Constructor connected with our impl structure
employee::employee(string name, int id) : pimpl(make_unique<impl>(name, id)) {}
employee::employee(const employee &other) : pimpl(new impl(*other.pimpl)) {}
employee &employee::operator=(employee emp)
{
    swap(pimpl, emp.pimpl);
    return *this;
}
employee::~employee() = default;
int employee::getid() { return pimpl->id; }
void employee::setid(int id)
{
    pimpl->id = id;
    int a = sizeof(impl);
}
//added methods
int employee::gettier() { return pimpl->tier; }
void employee::settier(int tier)
{
    if (tier > 0 && tier <= 10)
        pimpl->tier = tier;
}
int employee::getyears() { return pimpl->years; }
void employee::setyears(int years) { pimpl->years = years; }
int employee::calc_salary() { return pimpl->calc_salary(); }