#include <iostream>
using namespace std;
#include "Wrapper.hpp"

//testing given
void test()
{
    mysql_wrapper mysql("localhost", "admin", "badpassword");
    if (!mysql.init())
    {
        cout << "oops\n";
        return;
    }
    auto myptr = mysql.myptr; // this would be the internal mysql pointer
    // mysql C api calls would be called here
} // end of function... the database should be disconnected when it gets to here...

int main(void)
{
    test();
    return 0;
}