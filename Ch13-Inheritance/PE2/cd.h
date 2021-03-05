//Mostly their code

// base class
class Cd // represents a CD disk
{
private:
    int perfLen, labelLen;
    char *performers;
    char *label;
    int selections;  // number of selections
    double playtime; // playing time in minutes
public:
    Cd(const char *prfs, const char *lbl, int plays, double time);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
    Cd &operator=(const Cd &d);
};