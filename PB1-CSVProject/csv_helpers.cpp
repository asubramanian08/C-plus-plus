#include <istream>
#include <regex>
#include <stdexcept>
#include <string_view>
#include "csv_classes.hpp"
#include "csv_helpers.hpp"
using namespace std;

string_view readCSVLine(istream &in, bool peek)
{
    streampos org = in.tellg();
    string line_str;
    getline(in, line_str);
    string_view line_view = static_cast<string_view>(line_str);
    if (peek)
        in.seekg(org, std::ios_base::beg);
    return line_view;
}

int REGEX_sortType(string_view field)
{
    int type = csv_line::Str;
    regex int_expr("^[0-9]+$"), dat_expr("^[0-9]+/[0-9]+/[0-9]+$");
    if (regex_match(field.data(), int_expr))
        type = csv_line::Int;
    else if (regex_match(field.data(), dat_expr))
        type = csv_line::Dat;
    return type;
}