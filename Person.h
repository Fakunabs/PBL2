#ifndef Person_h
#define Person_h
#include <bits/stdc++.h>
#include "Day.h"

using namespace std;

class Person{
private:
    string Name;
    string PhoneNumber;
    Day DayOfBirth;
public:
    Person(){};
    Person(string Name,string PhoneNumber,Day DayOfBirth):Name(Name),PhoneNumber(PhoneNumber),DayOfBirth(DayOfBirth){};
    Person(const Person &P);
    ~Person(){}
    void setName(string Name);
    string getName() const;
    void setPhoneNumber(string PhoneNumber);
    string getPhoneNumber() const;
    void setNS(Day D);
    Day getNS() const;
    void printfPerson();
};

#endif // Person_h
