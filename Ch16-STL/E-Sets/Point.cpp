#include <cmath>
#include <ostream>
//made in TE2 modified in TE5 for hash, equal, and <<
struct point
{
    double x, y;
    point(double x, double y) : x(x), y(y) {}
    bool operator<(const point &pt) const { return hypot(x, y) < hypot(pt.x, pt.y); }
    bool operator==(const point &pt) const { return x == pt.x && y == pt.y; }
    friend ostream &operator<<(ostream &os, const point &pt) { return os << pt.x << ' ' << pt.y; };
    friend hash<point>;
};
template <>
struct hash<point>
{
    size_t operator()(const point &pt) const
    {
        return (hash<double>()(pt.x) << 4) ^ (hash<double>()(pt.y) >> 3) ^ 751764953839;
    }
};