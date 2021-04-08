#include <stdexcept>
#include <string>

class bad_avg : public std::logic_error
{
public:
    bad_avg(std::string mesg, double x, double y)
        : logic_error(mesg + "\nValues are " +
                      std::to_string(x) + ", " +
                      std::to_string(y)){};
};
class bad_hmean : public bad_avg
{
public:
    bad_hmean(double x, double y, std::string f_nm = "hmean", std::string prob = "a is -b")
        : bad_avg(f_nm + ": " + prob, x, y){};
};
class bad_gmean : public bad_avg
{
public:
    bad_gmean(double x, double y, std::string f_nm = "gmean()", std::string prob = "a < 0 or b < 0")
        : bad_avg(f_nm + ": " + prob, x, y){};
};