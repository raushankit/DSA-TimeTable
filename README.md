# TimeTable (DSA Course Project)

**Objective:** Make A timetable for the given input.

## Table of contents

- [General info](#general-info)
- [Technologies](#technologies)
- [Setup](#setup)

## General info

TimeTable Generator generates a file with inputs in the below format and rules

- [Sample Input](#sample-input)
- [Rules](#gen-rules)
- [Output](#sample-output)

### Sample Input

**_three numbers in input corresponds to <tutorial, Lab, Lectures>_**

```
1               // number of input data
2 1 5           // maximum number of classes for each category per day
1 3 1           // maximum duration of classes for each category
2               // maximum duration of break between classes

ECE             // department name
DEPT CORE       // subject type
5               // number of subjects
0 1 3 abc def   // subject description
0 0 2 abc def
1 1 3 abc def
0 1 2 abc def
0 0 3 abc def
DEPT ELECTIVE
2
0 0 2 abc def
0 0 1 abc def
OPEN ELECTIVE
1
0 0 1 abc def
MINOR
1
1 0 3 abc def

```

### Rules

1. One subject can have only 1 class in a day.
2. tutorials can have 2 slots one : 1st and two : 6th if required
3. Lab takes up 3 slots (3 hours as same as institute)
4. Lectures can take 7th to 12th slots.

### Output

Output of the corresponding input(if possible) is displayed on the terminal as well as a copy is saved in output folder

## Technologies

Project uses:

- C++
- GNU Make

## Setup

- clone project

```
git clone https://github.com/raushankit/DSA-TimeTable.git
```

- to run project

```make
make run
```

> > or

```
make
./a.out
```
