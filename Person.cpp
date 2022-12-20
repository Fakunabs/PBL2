#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"

Person::Person(const Person &P)
{
    this->Name=P.Name;
    this->PhoneNumber=P.PhoneNumber;
    this->DayOfBirth=P.DayOfBirth;
}

void Person::setName(string Name)
{
    this->Name=Name;
}
string Person::getName() const
{
    return Name;
}
void Person::setPhoneNumber(string PhoneNumber)
{
    this->PhoneNumber=PhoneNumber;
}
string Person::getPhoneNumber() const
{
    return PhoneNumber;
}
void Person::setNS(Day D)
{
    this->DayOfBirth=D;
}
Day Person::getNS() const
{
    return DayOfBirth;
}

void Person::printfPerson()
{
    cout << getName() << getPhoneNumber() << getNS();
}
