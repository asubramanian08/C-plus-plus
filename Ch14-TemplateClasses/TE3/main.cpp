#include <iostream>
#include "myPair.hpp"
using namespace std;

int main(void)
{
    myPair<bool, bool> myBools(false, false);
    cout << myBools << endl;
    cout << "Enter two bools(true,false): ";
    cin >> myBools;
    cout << myBools << endl;
    return 0;
}