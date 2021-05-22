#include "MYSQL.cpp"
class mysql_wrapper
{
private:
    const char *host, *user, *password;
    bool init_called;

public:
    MYSQL *myptr;
    mysql_wrapper(const char *host, const char *user, const char *password);
    bool init();
    void disconnect();
};