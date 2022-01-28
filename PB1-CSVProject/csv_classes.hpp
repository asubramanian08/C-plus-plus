#include <variant>

class csv_line
{
private:
    std::string_view line;
    std::variant<int, std::string> sortfield;

public:
    csv_line(std::string_view ln, int col, int sortType);
    enum Types { Int, Str, Dat };
    bool operator<(const csv_line &cl) const;
    bool operator>(const csv_line &cl) const;
    friend std::ostream &operator<<(std::ostream &os, const csv_line &cl);
};