// Mostly their code execpt replaced sections and where I have written "my code"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

/*template <class T> // functor class defines operator()() class TooBig
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T &t) : cutoff(t) {}
    bool operator()(const T &v) { return v > cutoff; }
};
void outint(int n) { std::cout << n << " "; }*/

auto prInt = [](int n) /* My code */
{ std::cout << n << " "; };

int main()
{
    using std::cout;
    using std::endl;
    using std::list;
    // TooBig<int> f100(100); // limit = 100
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); // range constructor
    list<int> etcetera(vals, vals + 10);
    // C++11 can use the following instead:
    // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    // list<int> etcetera{50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), /*outint*/ prInt);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), /*outint*/ prInt);
    cout << endl;
    yadayada.remove_if(/*f100*/ [cutoff = 100](auto v)
                       { return v > cutoff; }); // use a named function object
    etcetera.remove_if(/*TooBig<int>(200)*/ [cutoff = 200](auto v)
                       { return v > cutoff; }); // construct a function object
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), prInt);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), prInt);
    cout << endl;
    return 0;
}