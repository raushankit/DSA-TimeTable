#ifndef _DEPT_
#define _DEPT_
#include "scalar.h"
#include "course.h"
#include "pair.h"

class dept{
    int *max_class, *class_dur;
    int Break;
    string name;
    scalar<course> *d;
    
    public:
    dept();
    ~dept();
    void setName(string);
    string getName();
    int *getMaxClass();
    void setMaxClass(int*);
    int* getClassDur();
    void setClassDur(int*);
    int getBreak();
    void setBreak(int);
    void insertCourse(int, course);
    friend ostream& operator<<(ostream &, const dept&);
    bool checkData();
    scalar<duo<int, string>> extractData();
};

#endif
