#include "cd.h"

class Classic : public Cd
{
private:
    int workLen;
#define DEF_WORK "No primary work"
    char *primWork;

public:
    //special members
    Classic(const char *prfs, const char *lbl, const char *p_work, int plays, double time);
    Classic(const Classic &cls);
    Classic();
    virtual ~Classic();
    //normal function
    virtual void Report() const;
    Classic &operator=(const Classic &cls);
};