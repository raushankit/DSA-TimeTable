#include <iostream>
#include <sstream>
#include <fstream>
#include "classes/timetable.h"
#include "classes/dept.h"

using namespace std;

int* parse(string);

int* getInput(dept &);

timetable maketimetable(scalar<duo<int, string>> &, int*, int);
