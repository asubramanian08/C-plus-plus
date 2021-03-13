//Teacher's shell given (function implementations are mine)
#include <string>
using namespace std;

class Gum
{
public:
    virtual void empty() {} //dynamic_cast needs one virtual method
    string me() const { return string("Class ") + string(typeid(*this).name()); }
};
class Chewing : public Gum
{
};
class Bubble : public Gum
{
};
class Experimental : public Gum
{
};
class GumMachine
{
private:
    int count = 0;

public:
    Gum *dispense() // return either a Chewing, Bubble or Experimental object
    {
        Gum *ret;
        switch (count % 3)
        {
        case 0:
            ret = new Chewing();
            break;
        case 1:
            ret = new Bubble();
            break;
        case 2:
            ret = new Experimental();
            break;
        default:
            ret = new Gum(); //In case
        }
        count++;
        return ret;
    }
};