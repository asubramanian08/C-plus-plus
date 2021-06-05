#include "MYSQL.cpp"
class mysql_wrapper
{
private:
    const char *host, *user, *password;
    bool init_called = false;

public:
    MYSQL *myptr;
    mysql_wrapper(const char *host, const char *user, const char *password);
    bool init();
    void disconnect();
    ~mysql_wrapper() { disconnect(); }
};