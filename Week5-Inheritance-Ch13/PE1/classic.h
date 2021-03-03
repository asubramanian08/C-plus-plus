#include "cd.h"

class Classic : public Cd
{
private:
    const static int WORK_MAXLEN = 30;
    char primWork[WORK_MAXLEN];

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