#include <iostream>
#include <exception>
using namespace std;

int GetNum()
{
    cout << "Enter a number of 1 to 10: ";
    int val;
    cin >> val;
    if (val < 1)
        throw underflow_error("GetNum: Underflow: Number less then 1");
    if (val > 10)
        throw overflow_error("GetNum: Overflow: Number greater then 10");
    return val;
}

//part b
int betweenFunc(void)
{
    return GetNum();
}
//Yes, using the between function has the same effect.
//The expections go threw the call stack until it is in a try block.

//teacher's test code
int main(void)
{
    int i;
    while (1)
    {
        try
        {
            //i = GetNum();      //part a
            i = betweenFunc(); //part b
            cout << i << endl;
        }
        catch (underflow_error &e)
        {
            cout << e.what() << endl;
        }
        catch (overflow_error &e)
        {
            cout << e.what() << endl;
        }
    }
    return 0;
}