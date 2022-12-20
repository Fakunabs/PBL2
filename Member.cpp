#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"
#include "Member.h"

using namespace std;

string Member::getID() const
{
    return this->getPhoneNumber();
}

int Member::getPoint() const
{
    return this->Point;
}

int Member::UpDatePoint(int point)
{
    return this->Point+=point;
}

Member Member::ReadNode(ifstream &file)
{
    string name,phone_number,line;
    int d,m,y;
    getline(file,name,'|');
    this->setName(name);

    getline(file,phone_number,'|');
    this->setPhoneNumber(phone_number);

    file >> d;
    getline(file,line,'/');
    file >> m;
    getline(file,line,'/');
    file >> y;
    getline(file,line,'|');
    Day D(d,m,y);

    this->setNS(D);

    file >> this->Point;

    getline(file,line,'\n');
    return *this;
}

void Member::SaveNode(ofstream &file) const
{
    file << this->getName();
    file << "|";

    file << this->getPhoneNumber();
    file << "|";

    Day D=this->getNS();

    file << D.getDay();
    file << "/";

    file << D.getMonth();
    file << "/";

    file << D.getYear();
    file << "|";

    file << this->Point;
}

istream &operator>>(istream &in,LinkedList<Member> &M)
{
    string name,sdt;
    Day ngaysinh;
    int diem=0;
    do{
        cout << "Nhap so dien thoai:";
        in >> sdt;
    }while(M.CheckID(sdt)==true);
    cout << "Nhap ho ten:";
    cin.ignore();
    getline(in,name);
    cout << "Nhap ngay sinh:" << endl;
    in >> ngaysinh;
    Member m(name,sdt,ngaysinh,diem);
    M.InsertNodeAfter(m);
    return in;
}

void Member::printfIntro() const
{
    cout << left << setw(20) << "Ho ten" ;
    cout << left << setw(18) << "So dien thoai";
    cout << left << setw(14) << "Nam sinh";
    cout << left << setw(10) << "Diem" ;
    cout << endl;
}
void Member::printfNode() const
{
    cout << left << setw(20) << this->getName() ;
    cout << left << setw(18) << this->getPhoneNumber();
    cout << this->getNS();
    cout << left << setw(10) << this->Point;
    cout << endl;
}

