#include <memory>
using namespace std;

//HELP
class myString
{
private:
    unique_ptr<char[]> str;

public:
    const char *data() { return str.get(); }
    const myString &operator==(const myString &s)
    {
        str = make_unique<char[]>(s.str.get());
        return *this;
    }
};

int main(void)
{

    return 0;
}