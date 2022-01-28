#include <fstream>
#include <string_view>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "csv_helpers.hpp"
#include "csv_classes.hpp"
using namespace std;

// regex pattern matching - helpers.cpp
// add the date to it -> different file
// inherit from the string class and add cast functionality
// HELP should csv_line::sortfield be with string or string_view

int main(int argc, const char *argv[])
{
    if (argc != argCt)
        throw invalid_argument("./csv_main {input_file} {output_file} FIELD <Ascend|Decend|A|D>");
    ifstream in(argv[inF]);
    int sortCol = atoi(argv[fld]);
    string_view csv_header = getCSVLine(in, false);
    string_view sortfield = getField(getCSVLine(in, true), sortCol);
    int sortType = isdigit(sortfield[0]) ? csv_line::Int : csv_line::Str;
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