#include <iostream>
using namespace std;
#include "employee.hpp"

int main()
{
    employee bob("Bob", 10), joe("Joe", 0);
    employee temp(bob);
    joe.setid(42);
    cout << joe.getid();
    bob = joe;
}