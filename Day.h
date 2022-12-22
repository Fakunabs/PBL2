#ifndef Day_h
#define Day_h
#include <bits/stdc++.h>

using namespace std;

class Day{
private:
    int day;
    int month;
    int year;
public:
    Day(){}
    Day(int day,int month,int year):day(day),month(month),year(year){};
    Day(const Day &D);
    ~Day();
    friend istream &operator>>(istream &in,Day &D);
    friend ostream &operator<<(ostream &out,const Day &D);
    Day operator=(const Day &D);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int lastDay(int m,int y);
    bool checkDay();
    bool operator<=(const Day &D);
    void printfDay() const;
};

#endif // Day_h