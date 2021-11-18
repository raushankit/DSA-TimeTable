#include "prof.h"

prof::prof() : name(""), course_code(""){};
prof::prof(string nam, string code)
{
    name = nam;
    course_code = code;
    available = new bool[11];
    for (int i = 0; i < 11; i++)
        available[i] = true;
}
prof::prof(const prof &p)
{
    name = p.name;
    course_code = p.course_code;
    available = p.available;
}
prof &prof::operator=(const prof &p)
{
    if (this != &p)
    {
        available = new bool[11];
        for (int i = 0; i < 11; i++)
        {
            available[i] = p.available[i];
        }
        name = p.name;
        course_code = p.course_code;
    }
    return *this;
}

int prof::getAvailability()
{
    for (int i = 0; i < 11; i++)
    {
        if (available[i])
            return i + 1;
    }
    return 0;
}
void prof::setName(string name) { this->name = name; }
string prof::getName() { return name; }
void prof::setCourseCode(string code) { course_code = code; }
string prof::getCourseCode() { return course_code; }
ostream &operator<<(ostream &out, const prof &p)
{
    out << "Prof name: " << p.name << endl;
    out << "Course Code: " << p.course_code << endl;
    return out;
}
