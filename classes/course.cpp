#include "course.h"

course::course() : n_lectures(0), n_tut(false), n_lab(false), pr(){};
course::course(int n, bool b, bool c, prof pt)
{
    n_lectures = n;
    n_tut = b;
    n_lab = c;
    pr = pt;
}
course::course(const course &p)
{
    n_lectures = p.n_lectures;
    n_tut = p.n_tut;
    n_lab = p.n_lab;
    pr = p.pr;
}
course &course::operator=(const course &p)
{
    if (this != &p)
    {
        n_lectures = p.n_lectures;
        n_tut = p.n_tut;
        n_lab = p.n_lab;
        pr = p.pr;
    }
    return *this;
}
ostream &operator<<(ostream &out, const course &p)
{
    out << p.pr;
    out << "Lectures: " << p.n_lectures << endl;
    out << "Tutorial: " << p.n_tut << endl;
    out << "Lab: " << p.n_lab << endl;
    return out;
}
prof course::getProf() { return pr; }
void course::setProf(prof p) { pr = p; }
bool course::getTut() { return n_tut; }
void course::setTut(bool b) { n_tut = b; }
bool course::getLab() { return n_lab; }
void course::setLab(bool b) { n_lab = b; }
int course::getLecture() { return n_lectures; }
void course::setLecture(int n) { n_lectures = n; }
