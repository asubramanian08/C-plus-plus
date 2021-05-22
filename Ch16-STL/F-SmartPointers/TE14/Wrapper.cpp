#include "Wrapper.hpp"
mysql_wrapper::mysql_wrapper(const char *host, const char *user, const char *password)
    : host(host), user(user), password(password) { init_called = false; }
bool mysql_wrapper::init()
{
    myptr = mysql_init();
    if (myptr == nullptr)
        return false;
    myptr = mysql_real_connect(myptr, host, user, password);
    init_called = true;
    return true;
}
void mysql_wrapper::disconnect()
{
    if (!init_called || myptr == nullptr)
        return;
    mysql_close(myptr);
    init_called = false;
}