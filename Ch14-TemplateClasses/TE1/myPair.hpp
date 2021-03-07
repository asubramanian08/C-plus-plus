#define TPL_FS template <typename Fst, typename Sec> //template first second
#define PAIR_FS myPair<Fst, Sec>                     //pair of first, second

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
TPL_FS PAIR_FS &PAIR_FS::operator=(const PAIR_FS &src)
{
    f = src.f;
    s = src.s;
    return *this;
}
TPL_FS bool PAIR_FS::operator==(const PAIR_FS &b) const { return (f == b.f) && (s == b.s); }