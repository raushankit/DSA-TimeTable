#ifndef _PAIR_
#define _PAIR
#include <iostream>
using namespace std;
template <typename T, typename P>
struct duo
{
    T *p;
    P t;

    duo() : p(new T[3]){};
    friend ostream &operator<<(ostream &out, const duo &z)
    {
        out << z.p[0] << "-" << z.p[1] << "-" << z.p[2];
        out << " " << z.t << endl;
        return out;
    }
};

#endif
