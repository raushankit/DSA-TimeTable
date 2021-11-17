#include "function.h"

int main()
{
    dept d;
    int *n = getInput(d);
    cout << "This is formatted in form of dept timetable." << endl;
    cout << "The Input was take from a file (input.txt)" << endl;
    cout << "Additional contraints followed are: " << endl;
    cout << "1. one subject can have only 1 class in a day. " << endl;
    cout << "2. tutorials can have 2 slots one : 1st and two : 6th if required" << endl;
    cout << "3. Lab takes up 3 slots (3 hours as same as institute)" << endl;
    cout << "4. Lectures can take 7th to 12th slots" << endl;
    cout << "i have taken input to demontrate that time table cannot be built " << endl;
    cout << "properly because you cannot get a proper time table obeying the above CONSTRAINTS." << endl;
    cout << "you can change minor field from 1 0 3 to 1 0 2 and you will get a proper timetable" << endl;
    cout << "**MAXIMIZE TERMINAL TO GET A BETTER LOOK AT THE TIMETABLE." << endl;
    cout << "\n\n";

    if (d.checkData())
    {
        auto z = d.extractData();
        int p = d.getBreak();
        timetable tt = maketimetable(z, n, p);
        cout << tt << endl << endl;
        ofstream fout;
        fout.open("output/test_input1.txt", ofstream::out | ostream::trunc);
        fout << tt << endl << endl;
        fout.close();
    }
    return 0;
}
