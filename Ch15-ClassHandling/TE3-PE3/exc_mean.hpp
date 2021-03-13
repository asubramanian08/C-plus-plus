#include <stdexcept>
#include <string>

class bad_avg : public std::logic_error
{
public:
    bad_avg(std::string mesg, double x, double y)
        : logic_error(mesg + std::string("\nValues are ") + std::to_string(x) +
                      std::string(", ") + std::to_string(y)){};
};
class bad_hmean : public bad_avg
{
public:
    bad_hmean(double x, double y, const char *mesg = "hmean() -> the values entered add to zero")
        : bad_avg(mesg, x, y){};
};
class bad_gmean : public bad_avg
{
public:
    bad_gmean(double x, double y, const char *mesg = "gmean() -> one or more of the values entered were negative")
        : bad_avg(mesg, x, y){};
};