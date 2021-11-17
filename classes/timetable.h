#ifndef _TIMETABLE_
#define _TIMETABLE_
#include <iostream>
using namespace std;

class timetable{
    int hours,lec,Break;
    string *z[5]; //classes 5 days a week
    bool *f[5];

    public:
    timetable(int, int, int);
    ~timetable();
    friend ostream& operator<< (ostream &, const timetable&);
    void setString(string, int, int);
    int getSlotlec(int);
};

#endif
