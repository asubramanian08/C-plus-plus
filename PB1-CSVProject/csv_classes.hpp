#include <variant>

class date
{
private:
    unsigned int day : 6;
    unsigned int month : 5;
    unsigned int year : 12;

public:
    date();
    date(unsigned int d, unsigned int m, unsigned int y);
    date(const std::string &dat); // day first
    int operator<=>(const date &d) const;
};

class csv_line
{
private:
    std::string_view line;
    std::variant<int, std::string, date> sortfield;

public:
    csv_line(std::string_view ln, int col, int sortType);
    enum Types { Int, Str, Dat };
    bool operator<(const csv_line &cl) const;
    bool operator>(const csv_line &cl) const;
    friend std::ostream &operator<<(std::ostream &os, const csv_line &cl);
};