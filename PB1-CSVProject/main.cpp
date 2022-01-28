#include <fstream>
#include <iostream>
#include <string_view>
#include <variant>
#include <string>
#include <vector>
using namespace std;

// add the date to it -> different file
// inherit from the string class and add cast functionality

string_view getcsvline(string_view &csvbuf)
{
    auto endLine = csvbuf.find_first_of("\n");
    string_view line = csvbuf.substr(0, endLine);
    csvbuf.remove_prefix(endLine + 1);
    return line;
}

string_view getField(string_view ln, int col)
{
    int fieldStart = 0;
    for (int i = 0; i < col; i++)
        fieldStart = ln.find(',', fieldStart) + 1;
    int end = ln.find(',', fieldStart);
    if (end == string_view::npos)
        end = ln.size();
    return ln.substr(fieldStart, end - fieldStart);
}

class csv_line
{
private:
    string_view line;
    variant<int, string> sortfield; // HELP string or string_view

public:
    csv_line(string_view ln, int col, int sortType)
    {
        sortfield = static_cast<string>(getField(line = ln, col));
        if (sortType == 0) // int, add date to it later
            sortfield = stoi(get<string>(sortfield));
    }
    bool operator<(const csv_line &cl) const { return sortfield < cl.sortfield; }
    bool operator>(const csv_line &cl) const { return sortfield > cl.sortfield; }
    friend ostream &operator<<(ostream &os, const csv_line &cl) { return os << cl.line; }
};

void dumpCSV(string_view csv_header, const vector<csv_line> &csv)
{
    ofstream out("ordered_csv.txt");
    out << csv_header << endl;
    for (const csv_line &ln : csv)
        out << ln << endl;
}

int main(int argc, char *argv[]) // filename, feild sort by, ascending / deceonding
{
    // ifstream("csv_data.txt"); // read this YES HELP?
    // if (argc < 4) // raise an error??
    //  cerr << "Incorrect parametes: ./main {data_file} FEILD <Ascend|Decend|A|D>" << endl;
    //  return EXIT_FAILURE;
    int sortCol = atoi(argv[2]);
    char buffer[] = "name,age\nJoe,42\nFred,21\nAlbert,33\n"; // read from file
    string_view csv_view(buffer), csv_header = getcsvline(csv_view);
    string_view sortfield = getField(csv_view.substr(0, csv_view.find_first_of("\n")), sortCol);
    int sortType = isdigit(sortfield[0]) ? 0 : 1; // based on variant index //regex for this?
    vector<csv_line> csv;
    while (!csv_view.empty())
        csv.push_back(csv_line(getcsvline(csv_view), sortCol, sortType));
    if (toupper(argv[3][0]) == 'A') // ascending // HELP - problem
        sort(csv.begin(), csv.end(), less<csv_line>());
    else // descending  // test that its 'D' or else raise an error
        sort(csv.begin(), csv.end(), greater<csv_line>());
    dumpCSV(csv_header, csv); // print
}