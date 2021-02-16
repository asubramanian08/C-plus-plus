#include <iostream>
using namespace std;

//pro. ex. q1
#include "cow.hpp"

//pro. ex. q2
#include "string2.hpp"

int main(void)
{
    //pro. ex. q1
    cout << "Cow program starting" << endl;
    Cow cow1;
    Cow cow2("Bessie", "Milking", 10000);
    cout << "Cow with default contructor" << endl;
    cow1.ShowCow();
    cout << "Cow with each value specified, contructor" << endl;
    cow2.ShowCow();
    cout << "Assignment operator for the first cow" << endl;
    cow1 = cow2;
    cow1.ShowCow();
    cout << "copy contractor with a new cow" << endl;
    Cow cow3(cow2);
    cow3.ShowCow();
    cout << "Cow program ended" << endl
         << endl;

    //pro. ex. q2 (they wrote test code)
    cout << "String program starting" << endl;
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;              // overloaded << operator
    cin >> s3;               // overloaded >> operator
    s2 = "My name is " + s3; // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase
    cout << "The string\n"
         << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red"; // String(const char *),
    // then String & operator=(const String&)
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "String program ended\n";

    return 0;
}