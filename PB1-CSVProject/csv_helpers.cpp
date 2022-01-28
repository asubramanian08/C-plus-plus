#include <istream>
#include <stdexcept>
#include <string_view>
#include "csv_helpers.hpp"
using namespace std;

string_view getField(string_view ln, int col)
{
    size_t fieldStart = 0;
    for (int i = 0; i < col; i++, fieldStart++)
        if ((fieldStart = ln.find(',', fieldStart)) == string_view::npos)
            throw range_error("The sort field must be in range");
    size_t end = ln.find(',', fieldStart);
    if (end == string_view::npos)
        end = ln.size();
    return ln.substr(fieldStart, end - fieldStart);
}

string_view getCSVLine(istream &in, bool peek)
{
    streampos org = in.tellg();
    string strLine;
    getline(in, strLine);
    string_view viewLine = static_cast<string_view>(strLine);
    if (peek)
        in.seekg(org, std::ios_base::beg);
    return viewLine;
}