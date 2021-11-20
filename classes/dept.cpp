#include "dept.h"

dept::dept() : max_class(new int[3]), class_dur(new int[3]), Break(0), name(""), d(new scalar<course>[4]) {}

dept::~dept()
{
    delete[] d;
    delete[] max_class;
    delete[] class_dur;
}

ostream &operator<<(ostream &out, const dept &p)
{
    out << "Dept. Name : " << p.name << endl;
    out << "Course type : ";
    out << "In a single day maximum " << p.max_class[0] << " tutorials, ";
    out << p.max_class[1] << " lab and " << p.max_class[2] << " lectures can be taken. \n";
    out << "for one tut there is/are " << p.class_dur[0] << " hour(s) " << endl;
    out << "for one lab there is/are " << p.class_dur[1] << " hour(s) " << endl;
    out << "for one lecture there is/are " << p.class_dur[2] << " hour(s) " << endl;
    out << "A break of " << p.Break << " hours." << endl;
    string course_type[] = {"DEPT CORE", "DEPT ELECTIVE", "OPEN ELECTIVE", "MINOR"};
    for (int i = 0; i < 4; i++)
    {
        out << course_type[i] << "\n";
        p.d[i].print(out);
    }
    cout << "\n";
    return out;
}

void dept::setName(string n) { name = n; }

string dept::getName() { return name; }

void dept::insertCourse(int n, course p)
{
    d[n].push(p);
}

int *dept::getMaxClass() { return max_class; }

int *dept::getClassDur() { return class_dur; }

int dept::getBreak() { return Break; }

void dept::setMaxClass(int *p)
{
    max_class = new int[3];
    for (int i = 0; i < 3; i++)
    {
        max_class[i] = p[i];
    }
}

void dept::setClassDur(int *p)
{
    class_dur = new int[3];
    for (int i = 0; i < 3; i++)
    {
        class_dur[i] = p[i];
    }
}

void dept::setBreak(int m) { Break = m; }

scalar<duo<int, string>> dept::extractData()
{
    duo<int, string> tl;
    tl.p[0] = tl.p[1] = tl.p[2] = 0;
    scalar<duo<int, string>> p;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            duo<int, string> temp;
            tl.p[0] += (temp.p[0] = d[i][j].getLecture());
            temp.t = d[i][j].getProf().getCourseCode();
            tl.p[1] += (temp.p[1] = d[i][j].getTut());
            tl.p[2] += (temp.p[2] = d[i][j].getLab());
            p.push(temp);
        }
    }
    tl.t = "Total";
    p.push(tl);
    return p;
}

bool dept::checkData()
{
    int m_lec, m_tut, m_lab;
    m_tut = max_class[0];
    m_lab = max_class[1];
    m_lec = max_class[2];
    int t_lec = 0, t_tut = 0, t_lab = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            t_lec += d[i][j].getLecture();
            t_tut += d[i][j].getTut();
            t_lab += d[i][j].getLab();
        }
    }
    bool flag = true;
    if (m_lec > 6)
    {
        cout << " no more than 6 lectures per day is allowed. " << endl;
        flag = false;
    }
    if (m_tut > 2)
    {
        cout << " no more than 2 tutorials per day is allowed. " << endl;
        flag = false;
    }
    if (m_lab > 6)
    {
        cout << " no more than 1 lab per day is allowed. " << endl;
        flag = false;
    }
    if (t_lec > 5 * m_lec)
    {
        cout << "Insufficient time for lectures" << endl;
        flag = false;
    }
    if (t_lab > 5 * m_lab)
    {
        cout << "Insufficient time for lab classes." << endl;
        flag = false;
    }
    if (t_tut > 5 * (m_tut - Break / 2))
    {
        cout << "Insufficient time for tutorials." << endl;
        flag = false;
    }
    return flag;
}
