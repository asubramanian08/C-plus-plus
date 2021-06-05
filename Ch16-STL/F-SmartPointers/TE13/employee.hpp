#pragma once
//given and added to
#include <memory>
#include <string>
using namespace std;

class employee
{
private:
    struct impl;            //makes compiling faster
    unique_ptr<impl> pimpl; //pointer to implementation
public:
    employee(string name, int id);
    employee(const employee &other);
    employee &operator=(employee emp);
    ~employee();
    int getid();
    void setid(int);
    //added methods
    int gettier();
    void settier(int);
    int getyears();
    void setyears(int);
    int calc_salary();
};