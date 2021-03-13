#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const char *mesg = "hmean() -> the values entered add to zero")
        : logic_error(mesg){};
};
class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const char *mesg = "gmean() -> one or more of the values entered were negative")
        : logic_error(mesg){};
};