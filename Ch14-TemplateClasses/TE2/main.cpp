#include <iostream>
#include "myPair.hpp"
using namespace std;

int main(void)
{
    myPair<int, std::string> stuff;
    cout << "Enter an int and a word: ";
    cin >> stuff;
    cout << "You entered " << stuff << endl;
    return 0;
}