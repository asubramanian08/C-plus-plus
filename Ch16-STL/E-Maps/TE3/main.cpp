#include <string>
#include <iostream>
#include <map>
using namespace std;

//he wrote the employee class except from the overloaded operators
class employee
{
private:
    string firstname;
    string lastname;

public:
    employee(const string &f, const string &l) : firstname(f), lastname(l) {}
    employee() = delete; //  no default constructor...

    bool operator<(const employee &emp) const
    {
        if (this->lastname == emp.lastname)
            return this->firstname < emp.firstname;
        return this->lastname < emp.lastname;
    }
    friend ostream &operator<<(ostream &os, const employee &emp)
    {
        return os << emp.lastname << ", " << emp.firstname;
    }
};
#define salPair(f, l, sal) make_pair(employee(f, l), sal)

int main(void)
{
    //testing was not part of the question
    //just making an empty map
    map<employee, double> salary = {
        salPair("Bob", "Johnson", 25.69),
        salPair("Rob", "William", 27.99),
        salPair("Lob", "Brown", 9.999),
        salPair("José", "Brown", 10000.99)};
    for (auto emp : salary)
        cout << "Name: " << emp.first << "; Salary: " << emp.second << endl;
    return 0;
}