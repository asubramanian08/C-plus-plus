#include <iostream>
#include "myPair.hpp"
using namespace std;

//teacher's code
int main(void)
{
    myPair<int, int> i0, i1(2, 3), i2(i1);
    if (i1 == i2)
        i0 = i2;                // should execute
    cout << (i0 == i2) << endl; // should be 1
    myPair<string, int> Pop[] = {
        {"China", 1427647786},
        {"India", 1352642280},
        {"USA", 327096265},
        {"Tokelau", 1319}};
    for (int i = 0; i < sizeof(Pop) / sizeof(myPair<string, int>); i++)
    {
        cout << Pop[i].first() << "\t" << Pop[i].second() << endl;
    }
    myPair<string, int> USA(Pop[2]);
    cout << USA.first() << "\t" << USA.second() << endl;
    myPair<string, int> temp1, temp2, temp3;
    temp1 = temp2 = temp2 = temp3 = temp3 = USA = USA;
    cout << (temp1 == Pop[2]) << endl;
    return 0;
}