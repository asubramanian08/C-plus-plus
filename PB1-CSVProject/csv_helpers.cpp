#include <istream>
#include <regex>
#include <stdexcept>
#include <string_view>
#include "csv_classes.hpp"
#include "csv_helpers.hpp"
using namespace std;

string_view readCSVLine(string_view &csv_view, string_view &line, bool advance)
{
    size_t endLine = csv_view.find("\n");
    line = csv_view.substr(0, endLine);
    endLine = min(endLine, csv_view.size() - 1);
    if (advance)
        csv_view.remove_prefix(endLine + 1);
    return line;
}

int REGEX_sortType(string_view field)
{
    int type = csv_line::Str;
    regex int_expr("^\\d+$"), dat_expr("^\\d+/\\d+/\\d+$");
    if (regex_match(field.begin(), field.end(), int_expr))
        type = csv_line::Int;
    else if (regex_match(field.begin(), field.end(), dat_expr))
        type = csv_line::Dat;
    return type;
}