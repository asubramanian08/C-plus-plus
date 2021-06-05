#include <iostream>
using namespace std;
#include "string.hpp"

int main(void)
{
    //test the code
    String hi("Hello string"), rep = hi;
    cout << "Length: " << rep.length() << endl
         << "String: " << hi << endl;
    rep.stringlow();
    cout << "New string: " << rep << endl;
    return 0;
}