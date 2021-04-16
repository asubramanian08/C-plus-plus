#include <iostream>
#include <string>
using namespace std;

#include "Extractor.h"

int main(void)
{
    //His test code
    Extractor e("moo"); // removes all the "moo"s
    string s;
    getline(cin, s); // type mmooomoooImomoooHamomoooteCowsmomooo!!
    e.extract(s);
    cout << e; // => IHateCows!!

    return 0;
}