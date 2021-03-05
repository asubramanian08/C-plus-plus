//Mostly their code

// base class
class Cd // represents a CD disk
{
private:
    const static int PERF_LEN = 50, LABEL_LEN = 20;
    char performers[PERF_LEN];
    char label[LABEL_LEN];
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