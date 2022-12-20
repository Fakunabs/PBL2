#include <bits/stdc++.h>
#include "Day.h"

using namespace std;

Day::Day(const Day &D)
{
    day=D.day;
    month=D.month;
    year=D.year;
}

istream &operator>>(istream &in,Day &D)
{
    do {
        cout << "Nhap ngay:";
        in >> D.day;
        cout << "Nhap thang:";
        in >> D.month;
        cout << "Nhap nam:";
        in >> D.year;
    } while (!D.checkDay());
    return in;
}

ostream &operator<<(ostream &out,const Day &D)
{
    D.printfDay();
    return out;
}

Day Day::operator=(const Day &D)
{
    if(this!=&D)
    {
        this->day=D.day;
        this->month=D.month;
        this->year=D.year;
    }
    return *this;
}

int Day::getDay() const
{
    return day;
}
int Day::getMonth() const
{
    return month;
}

int Day::getYear() const
{
    return year;
}

int Day::lastDay(int m,int y)
{
    int a[]={31,29,31,30,31,30,31,31,30,31,30,31};
    if (y%4==0 && y%400!=0) a[2]=28;
    return a[m];
}

bool Day::checkDay()
{
    if (year>2022) return false;
    if (month<1 || month>12) return false;
    if (day<1 || day>lastDay(month,year)) return false;
    return true;
}

void Day::printfDay() const
{
    cout << left << setw(2) << day << "/" << left << setw(2) << month << "/" << left << setw(8) << year;
}

Day::~Day()
{

}

bool Day::operator<=(const Day &D)
{
    if (this->year>D.year) return false;
    if (this->year==D.year && this->month>D.month) return false;
    if (this->year==D.year && this->month==D.month && this->day>D.day) return false;
    return true;
}
