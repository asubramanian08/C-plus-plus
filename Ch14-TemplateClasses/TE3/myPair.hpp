#include <iostream>
#include <string>
//TE1 defines:
#define TPL_FS template <typename Fst, typename Sec> //template first second
#define PAIR_FS myPair<Fst, Sec>                     //pair of first, second
//TE2 defines:
#define TPL_FS_ template <typename Fst_, typename Sec_> //template first second
#define PAIR_FS_ myPair<Fst_, Sec_>                     //pair of first, second

//teacher's class declaration
TPL_FS class myPair
{
private:
    Fst f;
    Sec s;

public:
    const Fst &first() const;
    const Sec &second() const;
    myPair();
    myPair(Fst _f, Sec _s);
    myPair(const myPair &source);
    PAIR_FS &operator=(const PAIR_FS &src);
    bool operator==(const PAIR_FS &b) const;
    TPL_FS_ friend std::ostream &operator<<(std::ostream &os, const PAIR_FS_ &mp);
    TPL_FS_ friend std::istream &operator>>(std::istream &is, PAIR_FS_ &mp);
};
//implementations (mine)
TPL_FS const Fst &PAIR_FS::first() const { return f; }
TPL_FS const Sec &PAIR_FS::second() const { return s; }
TPL_FS PAIR_FS::myPair(){};
TPL_FS PAIR_FS::myPair(Fst _f, Sec _s)
{
    f = _f;
    s = _s;
}
TPL_FS PAIR_FS::myPair(const myPair &source)
{
    f = source.f;
    s = source.s;
}
TPL_FS_ PAIR_FS_ &PAIR_FS_::operator=(const PAIR_FS_ &src)
{
    f = src.f;
    s = src.s;
    return *this;
}
TPL_FS_ bool PAIR_FS_::operator==(const PAIR_FS_ &b) const { return (f == b.f) && (s == b.s); }
//TE2 implementions
TPL_FS_ std::ostream &operator<<(std::ostream &os, const PAIR_FS_ &mp)
{
    os << '{' << mp.f << ", " << mp.s << '}';
    return os;
}
TPL_FS_ std::istream &operator>>(std::istream &is, PAIR_FS_ &mp)
{
    is >> mp.f >> mp.s;
    return is;
}

//TE3 everything
#define PAIR_BB myPair<bool, bool>
#define BIT1 (1 << 0)
#define BIT2 (1 << 1)
template <>
class myPair<bool, bool>
{
private:
    uint8_t val;

public:
    const bool &first() const;
    const bool &second() const;
    myPair();
    myPair(bool _f, bool _s);
    myPair(const myPair &source);
    PAIR_BB &operator=(const PAIR_BB &src);
    bool operator==(const PAIR_BB &b) const;
    friend std::ostream &operator<<(std::ostream &os, const PAIR_BB &mp);
    friend std::istream &operator>>(std::istream &is, PAIR_BB &mp);
};
const bool &PAIR_BB::first() const { return val & BIT1; }
const bool &PAIR_BB::second() const { return val & BIT2; }
PAIR_BB::myPair(bool _f, bool _s)
{
    val = 0;
    if (_f)
        val |= BIT1;
    if (_s)
        val |= BIT2;
}
PAIR_BB::myPair(const myPair &source)
{
    val = 0;
    if (source.first())
        val |= BIT1;
    if (source.second())
        val |= BIT2;
}
PAIR_BB &PAIR_BB::operator=(const PAIR_BB &src)
{
    val = src.val;
    return *this;
}
bool PAIR_BB::operator==(const PAIR_BB &b) const
{
    return val == b.val;
}
std::ostream &operator<<(std::ostream &os, const PAIR_BB &mp)
{
    os << '{';
    if (mp.first())
        os << "true";
    else
        os << "false";
    os << ", ";
    if (mp.second())
        os << "true";
    else
        os << "false";
    os << '}';
    return os;
}
std::istream &operator>>(std::istream &is, PAIR_BB &mp)
{
    mp.val = 0;
    std::string s1, s2;
    is >> s1 >> s2;
    if (s1 != "false")
        mp.val |= BIT1;
    if (s2 != "false")
        mp.val |= BIT2;
    return is;
}