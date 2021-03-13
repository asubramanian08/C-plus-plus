#include <iostream>
//#include "Gum4.hpp" //TE4
#include "Gum5.hpp" //TE5
using namespace std;

int main(void)
{
    //teacher gave outline for dispensing code
    GumMachine gummachine;
    //my initializations
    Chewing *pc;
    Bubble *pb;
    Experimental *pe;
    for (int i = 0; i < 6; i++)
    {
        Gum *g = gummachine.dispense();
        //figuring out what type - my code
        if ((pc = dynamic_cast<Chewing *>(g)))
            cout << pc->me() << '\n';
        else if ((pb = dynamic_cast<Bubble *>(g)))
            cout << pb->me() << '\n';
        else if ((pe = dynamic_cast<Experimental *>(g)))
            cout << pe->me() << '\n';
        else
            cout << "Type couldn't be found\n";
        delete g;
    }
    return 0;
}