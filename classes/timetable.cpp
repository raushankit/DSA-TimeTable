#include "timetable.h"

timetable::timetable(int n, int l, int b){
    hours = n;
    lec = l;
    Break = b;
    for(int i = 0;i < 5;i++){
        z[i] = new string[n];
        f[i] = new bool[n];
        for(int j = 0;j < n;j++){
            f[i][j] = true;
            z[i][j] = "";
        }
    }
}
timetable::~timetable(){
    for(int i = 0;i < 5;i++){
        delete[] z[i];
        delete[] f[i];
    }
}
void timetable::setString(string key, int day, int hour){
    z[day][hour] = key;
    f[day][hour] = false;
}
int timetable::getSlotlec(int day){
    for(int i = 6;i < 6+hours;i++){
        if(f[day][i]) return i;
    }
    return -1;
}
ostream &operator<<(ostream &out, const timetable &p){
    out << "_____";
    for(int i = 0;i < p.hours*10;i++) out << "_";
    out << endl;
    string day[] = {"|  MONDAY ","| TUESDAY ","|WEDNESDAY","| THURSDAY","|  FRIDAY "};
    for(int i = 0;i < 5;i++){
        out << "|          |";
        for(int j = 0;j < p.hours-p.lec-p.Break;j++){
            out << "         |";
        }
        for(int j = p.hours-p.lec-p.Break;j < p.hours;j++){
            out << "        |";
        }
        out << endl;
        out << day[i] << " | ";
        for(int j = 0;j < p.hours-p.lec-p.Break;j++){
            if(j > 0) cout << " ";
            if(p.z[i][j] == ""){
                out << "        |";
            }
            else{
                out << " " << p.z[i][j] << " |";
            }
        }for(int j = p.hours-p.lec-p.Break;j < p.hours;j++){
            if(p.z[i][j] == ""){
                out << "        |";
            }
            else{
                out << " " << p.z[i][j] << "  |";
            }
        }
        out << endl;
        out << "|__________|";
        for(int j = 0;j < p.hours-p.lec-p.Break;j++){
            out << "_________|";
        }
        for(int j = p.hours-p.lec-p.Break;j < p.hours;j++){
            out << "________|";
        }
        out << endl;
    }
    return out;
} 

