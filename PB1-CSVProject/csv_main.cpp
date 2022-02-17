#include <fstream>
#include <string_view>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "csv_classes.hpp"
#include "csv_helpers.hpp"
using namespace std;

int main(int argc, const char *argv[])
{
    // read entire input
    if (argc != argCt)
        throw invalid_argument("exc {input_file} {output_file} FIELD <Ascend|Decend|A|D>");
    ifstream in(argv[inF]);
    in.seekg(0, ios::end);
    size_t fileSize = in.tellg();
    in.seekg(0, ios::beg);
    char *csv_buf = new char[fileSize];
    copy_n(istreambuf_iterator<char>(in), fileSize, csv_buf);
    in.close();
    string_view csv_view(csv_buf, fileSize);

    // parse input: csv_header, csv
    int sortCol = atoi(argv[fld]);
    string_view csv_header = readCSVLine(csv_view, csv_header, true);
    string_view peekFirst = readCSVLine(csv_view, peekFirst, false);
    int sortType = REGEX_sortType(csv_line::getField(peekFirst, sortCol));
    vector<csv_line> csv;
    string_view currLine;
    while (!csv_view.empty())
        csv.push_back(csv_line(readCSVLine(csv_view, currLine, true), sortCol, sortType));
    if (toupper(argv[st][0]) == 'A') // ascending
        sort(csv.begin(), csv.end(), less<csv_line>());
    else if (toupper(argv[st][0]) == 'D') // descending
        sort(csv.begin(), csv.end(), greater<csv_line>());
    else
        throw invalid_argument("Invalid sort ordering. Options are <Ascend|Decend|A|D>");

    // print the sorted lines
    ofstream out(argv[outF]);
    out << csv_header << endl;
    for (const csv_line &ln : csv)
        out << ln << endl;
    out.close();
}