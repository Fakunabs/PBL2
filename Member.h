#ifndef Member_h
#define Member_h
#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"
#include "LinkedList.h"

class Member:public Person{
private:
    int Point;
public:
    Member(){};
    Member(string name,string sdt,Day ngaysinh,int Point):Person(name,sdt,ngaysinh),Point(Point){};
    ~Member(){};
    string getID() const;
    int getPoint() const;
    int UpDatePoint(int point);
    Member ReadNode(ifstream &file);
    void SaveNode(ofstream &file) const;
    friend istream &operator>>(istream &in,LinkedList<Member> &M);
    void printfIntro() const;
    void printfNode() const;
};

#endif // Member_h

