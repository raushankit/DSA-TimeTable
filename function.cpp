#include "function.h"

void rules()
{
    cout << "This is formatted in form of dept timetable." << endl;
    cout << "The input was take from a file (input.txt)" << endl;
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
}

int *parse(string inp)
{
    int *time = new int[3];
    stringstream ss(inp);
    ss >> time[0] >> time[1] >> time[2];
    return time;
}

int *getInput(dept &d)
{
    int *tip, *np;
    np = new int[6];
    const string inp_file = "test_input1.txt";
    ifstream fin("input/" + inp_file);
    int n;
    fin >> n;
    string inp = "";
    while (n--)
    {
        while (inp == "")
            getline(fin, inp);
        d.setMaxClass(parse(inp));
        tip = d.getMaxClass();
        inp = "";
        np[0] = tip[2];
        while (inp == "")
            getline(fin, inp);
        d.setClassDur(parse(inp));
        int gap;
        fin >> gap;
        d.setBreak(gap);
        np[5] = gap;
        inp = "";
        while (inp == "")
            getline(fin, inp);
        d.setName(inp);
        string CourseCode = inp.substr(0, 2);
        for (int i = 0; i < 4; i++)
        {
            inp = "";
            while (inp == "")
                getline(fin, inp);
            int m;
            fin >> m;
            np[1 + i] = m;
            while (m--)
            {
                inp = "";
                while (inp == "")
                    getline(fin, inp);
                stringstream ss(inp);
                bool tut, lab;
                int lec;
                string profName;
                ss >> tut >> lab >> lec;
                while (ss >> inp)
                {
                    profName += inp + " ";
                }
                prof pr = prof(profName, CourseCode + to_string(100 + i * 10 + m));
                course c_temp = course(lec, tut, lab, pr);
                d.insertCourse(i, c_temp);
            }
        }
    }
    fin.close();
    return np;
}

timetable maketimetable(scalar<duo<int, string>> &z, int *p, int Break)
{
    int n = z.size();
    timetable tt(p[0] + 6, p[0], p[5]);
    int n_l = z[n - 1].p[0];
    int g[5];
    for (int i = 0; i < 5; i++)
        g[i] = n_l / 5;
    for (int i = 0; i < n_l % 5; i++)
        g[4 - i]++;

    for (int i = 0; i < Break; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tt.setString("BREAK", j, 4 + i);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int j = 0, k = 0;
        while (j < 5 && k < n - 1)
        {
            if (z[k].p[0] > 0)
            {
                tt.setString(z[k].t, i, j + 6);
                z[k].p[0]--;
                j++;
            }
            k++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (z[i].p[0])
        {
            cout << "**" << z[i].t << " cannot be accomodated in time table .(We are following one subject per day)" << endl;
        }
    }
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (z[i].p[2])
        {
            tt.setString(z[i].t + "L", j, 1);
            tt.setString(z[i].t + "L", j, 2);
            tt.setString(z[i].t + "L", j, 3);
            j++;
        }
    }
    j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (z[i].p[1])
        {
            tt.setString(z[i].t + "T", j, 0);
            j++;
        }
    }
    return tt;
}
