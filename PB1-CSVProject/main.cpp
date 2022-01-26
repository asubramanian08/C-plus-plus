#include <string_view>
#include <variant>
#include <string>
using namespace std;

string_view &getsvline(string_view &csvbuf, string_view &line)
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
        sortfield = static_cast<string>(line.substr(fieldStart, line.find(',', fieldStart) - fieldStart));
    }
};

int main(void)
{
    char buffer[] = "name,age\n,Joe,42\nFred,33\n,Albert,21\n";
    string_view csv_view(buffer), csv_header;
    csv_header = getsvline(csv_view, csv_header);
}