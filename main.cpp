#include "function.h"

int main()
{
    dept d;
    int *n = getInput(d);
    rules();

    if (d.checkData())
    {
        auto z = d.extractData();
        int p = d.getBreak();
        timetable tt = maketimetable(z, n, p);
        cout << tt << endl
             << endl;
        ofstream fout;
        fout.open("output/test_input1.txt", ofstream::out | ostream::trunc);
        fout << tt << endl
             << endl;
        fout.close();
    }
    return 0;
}
