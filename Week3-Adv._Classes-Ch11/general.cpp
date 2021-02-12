#include <iostream>
using namespace std;

//ch. rev. q2
/* Friend functions are not called from a class object */

//ch. rev. q4
//In class - friend Stonewt operator*(double mult, const Stonewt5 &s);
//Out of class:
/*Stonewt operator*(double mult, const Stonewt &stn)
{
    return Stonewt(stn.stone * mult);
    //return stn * mult;
}*/

//ch. rev. q5 (operators that can't be overloaded)
/*Operator           |       Description
---------------------|---------------------------------
  sizeof             |       The sizeof operator
  .                  |       The membership operator
  .*                 |       The pointer-to-member operator
  ::                 |       The scope-resolution operator
  ?:                 |       The conditional operator
  typeid             |       An RTTI operator
  const_cast         |       A type cast operator
  dynamic_cast       |       A type cast operator
  reinterpret_cast   |       A type cast operator
  static_cast        |       A type cast operator*/

//ch. rev. q6
/*You can only use member functions to overload ""=,(),[], and ->" operators*/

//ch. rev. q7
/* Will go inside the real files (header and cpp file)
operator double() const { return mag; } */

//pro. ex. q4
#include "myTime3.hpp"
//See the changes in myTime3.hpp and myTime.cpp

//pro. ex. q5
#include "stonewt5.hpp"
//See the changes in stonewt5.hpp and stonewt5.cpp

//pro. ex. q6
#include "stonewt6.hpp"
//See the opperator changes in stonewt6.hpp and stonewt6.cpp
std::ostream &operator<<(std::ostream &os, const Stonewt6 &s)
{
    os << s.stone << " stone, " << s.pds_left << " pounds";
    return os;
}

//pro. ex. q7
#include "complexNum.hpp"

int main(void)
{
    //pro. ex. q4 (their run code)
    /*cout << "The time program stated" << endl;
    //usetime3.cpp -- using the fourth draft of the Time class
    // compile usetime3.cpp and mytime3.cpp together
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca; // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17; // member operator*()
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    cout << "Time program ended" << endl
         << endl;*/

    //pro. ex. q5
    /*cout << "Starting the stone weight program" << endl;
    Stonewt5 stn1(Stonewt5::ioForm::DOUB_LBS);
    Stonewt5 stn2(5.7, Stonewt5::ioForm::INT_LBS);
    Stonewt5 stn3(4, 54);
    cout << "Stone 1: " << stn1 << "Stone 2: " << stn2 << "Stone 3: " << stn3;
    cout << "Stone 1 + 2: " << stn1 + stn2;
    cout << "Stone 2 - 3: " << stn2 - stn3;
    cout << "5 * stone 3: " << 5 * stn3;
    cout << "Stone weight program ended" << endl;*/

    //pro. ex. q6
    /*cout << "Stone program with overloaded bool operators starting" << endl;
    Stonewt6 arr[6];
    arr[0] = Stonewt6();
    arr[1] = Stonewt6(5, 3.2);
    arr[2] = Stonewt6(17.83);
    int stones;
    double pounds;
    bool rType;
    for (int i = 3; i < 6; i++)
    {
        cout << "Getting" << i + 1 << "th element" << endl;
        cout << "Do you want to enter stones(1) or not(0): ";
        cin >> rType;
        if (rType)
        {
            cout << "Enter the number of stones: ";
            cin >> stones;
            cout << "Enter the left over pounds(double): ";
            cin >> pounds;
            arr[i] = Stonewt6(stones, pounds);
        }
        else
        {
            cout << "Enter the amount of pounds the thing is: ";
            cin >> pounds;
            arr[i] = Stonewt6(pounds);
        }
    }
    cout << "Finished getting elements" << endl;
    Stonewt6 comp_stn(11, 0);
    int grtr_eql = 0, largest = 0, smallest = 0;
    for (int i = 1; i < 6; i++)
    {
        if (arr[i] > arr[largest])
            largest = i;
        if (arr[i] < arr[smallest])
            smallest = i;
        if (arr[i] >= comp_stn)
            grtr_eql++;
    }
    cout << "There are " << grtr_eql << "values greater than or equal to 11 stones" << endl
         << "The " << largest << "th element is largest with a value of " << arr[largest] << endl
         << "The " << smallest << "th element is the smallest with a value of " << arr[smallest] << endl;
    cout << "Stone program with overloaded bool operators finished" << endl
         << endl;*/

    //pro. ex. q7 (Their test code)
    complex a(3.0, 4.0); // initialize to (3,4i)
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Complex number program done!\n";
    return 0;
}