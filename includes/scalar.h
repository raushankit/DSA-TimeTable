#ifndef _SCALAR_
#define _SCALAR_
#include <iostream>

using namespace std;

template <typename T>
class scalar
{
public:
    scalar();
    scalar(const scalar &);
    scalar &operator=(const scalar &);
    int size() const;
    void push(T);
    T &operator[](int);
    void print() const;
    void print(ostream &) const;
    void clear();

private:
    int n;
    int capacity;
    T *data;
};

#include "scalar.ipp"
#endif
