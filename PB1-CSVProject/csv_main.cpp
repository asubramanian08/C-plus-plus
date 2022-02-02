#include <fstream>
#include <string_view>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "csv_classes.hpp"
#include "csv_helpers.hpp"
using namespace std;

// HELP error when I try to find ',' in the data line it fails (getFeild)
// Is there are way to not use the csv_line::Types and just use templates
// HELP should csv_line::sortfield be with string or string_view

int main(int argc, const char *argv[])
{
    if (argc != argCt)
        throw invalid_argument("exc {input_file} {output_file} FIELD <Ascend|Decend|A|D>");
    ifstream in(argv[inF]);
    int sortCol = atoi(argv[fld]);
    string_view csv_header = getCSVLine(in, false);
    int sortType = REGEX_sortType(getField(getCSVLine(in, true), sortCol));
    vector<csv_line> csv;
    while (!in.eof())
        csv.push_back(csv_line(getCSVLine(in, false), sortCol, sortType));
    if (toupper(argv[st][0]) == 'A') // ascending
        sort(csv.begin(), csv.end(), less<csv_line>());
    else if (toupper(argv[st][0]) == 'D') // descending
        sort(csv.begin(), csv.end(), greater<csv_line>());
    else
        throw invalid_argument("Invalid sort ordering. Options are <Ascend|Decend|A|D>");
    ofstream out(argv[outF]);
    out << csv_header << endl;
    for (const csv_line &ln : csv)
        out << ln << endl;
}