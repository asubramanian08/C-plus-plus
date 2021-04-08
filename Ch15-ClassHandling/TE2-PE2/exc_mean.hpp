#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(std::string f_nm = "hmean", std::string prob = "a is -b")
        : logic_error(f_nm + ": " + prob){};
};
class bad_gmean : public std::logic_error
{
public:
    bad_gmean(std::string f_nm = "gmean()", std::string prob = "a < 0 or b < 0")
        : logic_error(f_nm + ": " + prob){};
};