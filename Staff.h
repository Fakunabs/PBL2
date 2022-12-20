#ifndef Staff_h
#define Staff_h
#include "Person.h"
#include "Day.h"
#include "LinkedList.h"

using namespace std;

class Staff:public Person{
private:
    string IDStaff;
    string CICard; // can cuoc cong dan
    string Address;
    string Email;
    float Wage; // tien cong (luong)
public:
    Staff(){};
    Staff(string IDStaff,string name,string sdt,Day ngaysinh,string CICard,
string Address,string Email,float Wage):Person(name,sdt,ngaysinh)
,IDStaff(IDStaff),CICard(CICard),Address(Address),Email(Email),Wage(Wage){};
    ~Staff(){};
    string getID() const;
    Staff ReadNode(ifstream &file);
    void SaveNode(ofstream &file) const;
    friend istream &operator>>(istream &in,LinkedList<Staff> &S);
    void printfIntro() const;
    void printfNode() const;
};

#endif // Staff_h

