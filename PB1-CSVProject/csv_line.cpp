#include <string>
#include <string_view>
#include <variant>
#include "csv_helpers.hpp"
#include "csv_classes.hpp"
using namespace std;

csv_line::csv_line(string_view ln, int col, int sortType)
{
    sortfield = static_cast<string>(getField(line = ln, col));
    if (sortType == Int)
        sortfield = stoi(get<string>(sortfield));
}

bool csv_line::operator<(const csv_line &cl) const { return sortfield < cl.sortfield; }

bool csv_line::operator>(const csv_line &cl) const { return sortfield > cl.sortfield; }

ostream &operator<<(ostream &os, const csv_line &cl) { return os << cl.line; }