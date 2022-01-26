#include <fstream>
#include <string_view>
#include <variant>
#include <string>
#include <vector>
using namespace std;
#define SORT_BY 1 // user input HELP??

string_view &getcsvline(string_view &csvbuf, string_view &line)
{
    auto endLine = csvbuf.find_first_of("\n");
    line = csvbuf.substr(0, endLine);
    csvbuf.remove_prefix(endLine + 1);
    return line;
}

class csv_line
{
private:
    string_view line;
    variant<int, string> sortfield; // HELP

public:
    csv_line(string_view &ln, int col)
    {
        line = ln;
        int fieldStart = 0;
        for (int i = 0; i < col; i++)
            fieldStart = line.find(',', fieldStart) + 1;
        int end = line.find(',', fieldStart);
        if (end == string_view::npos)
            end = line.size();
        sortfield = static_cast<string>(line.substr(fieldStart, end - fieldStart));
    }
    bool operator<(const csv_line &cl) const { return sortfield < cl.sortfield; }
    friend ostream &operator<<(ostream &os, const csv_line &cl) { return os << cl.line; } // Allowed?
};

void dumpCSV(string_view csv_header, const vector<csv_line> &csv)
{
    ofstream out("ordered_csv.txt");
    out << csv_header << endl;
    for (const csv_line &ln : csv)
        out << ln << endl;
}

int main(void)
{
    // ifstream("csv_data.txt"); // read this ? HELP
    char buffer[] = "name,age\n,Joe,42\nFred,33\n,Albert,21\n";
    string_view csv_view(buffer), csv_header, line;
    csv_header = getcsvline(csv_view, csv_header); // write type here?
    line = getcsvline(csv_view, line);             // find the type HELP
    vector<csv_line> csv;
    while (!csv_view.empty())
    {
        line = getcsvline(csv_view, line);
        csv.push_back(csv_line(line, SORT_BY));
    }
    sort(csv.begin(), csv.end()); // Work with varent HELP?, ascend or decend?
    dumpCSV(csv_header, csv);     // print
}