#ifndef _COURSE_
#define _COURSE_
#include "prof.h"

class course
{
public:
    course();
    course(int, bool, bool, prof);
    course(const course &);
    course &operator=(const course &);
    friend ostream &operator<<(ostream &, const course &);
    prof getProf();
    void setProf(prof);
    bool getTut();
    void setTut(bool);
    bool getLab();
    void setLab(bool);
    int getLecture();
    void setLecture(int);

private:
    int n_lectures;
    bool n_tut, n_lab;
    prof pr;
};

#endif
