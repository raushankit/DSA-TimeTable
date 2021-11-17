#ifndef _PROF_
#define _PROF_
#include <iostream>
using namespace std;

class prof{
    string name, course_code;
    bool* available;
    
    public:
    prof();
    prof(string, string);
    prof(const prof&);
    prof& operator=(const prof&);
    int getAvailability();
    void setName(string);
    string getName();
    void setCourseCode(string);
    string getCourseCode();
    friend ostream& operator<<(ostream &, const prof &);
};

#endif
