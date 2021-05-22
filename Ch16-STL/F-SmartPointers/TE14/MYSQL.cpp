struct MYSQL
{
};
//prototypes given
MYSQL *mysql_init() { return new MYSQL; }
MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *password) { return mysql; }
void mysql_close(MYSQL *mysql) { delete mysql; }