#include <string>
#include <string_view>
#include <variant>
#include "csv_classes.hpp"
using namespace std;

csv_line::csv_line(string_view ln, int col, int sortType)
{
    sortfield = static_cast<string>(getField(line = ln, col));
    if (sortType == Int)
        sortfield = stoi(get<string>(sortfield));
    else if (sortType == Dat)
        sortfield = static_cast<date>(get<string>(sortfield));
}

string_view csv_line::getField(string_view ln, int col)
{
    size_t fieldStart = 0;
    for (int i = 0; i < col; i++, fieldStart++)
        if ((fieldStart = ln.find(',', fieldStart)) == string_view::npos)
            throw range_error("The sort field must be in range");
    size_t fieldEnd = ln.find_first_of(",");
    if (fieldEnd == string_view::npos)
        fieldEnd = ln.size();
    return ln.substr(fieldStart, fieldEnd - fieldStart);
}

bool csv_line::operator<(const csv_line &cl) const { return sortfield < cl.sortfield; }

bool csv_line::operator>(const csv_line &cl) const { return sortfield > cl.sortfield; }

ostream &operator<<(ostream &os, const csv_line &cl) { return os << cl.line; }