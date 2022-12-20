#include <bits/stdc++.h>
#include "Person.h"
#include "Day.h"
#include "Staff.h"

using namespace std;

string Staff::getID() const
{
    return this->IDStaff;
}

Staff Staff::ReadNode(ifstream &file)
{
    string name,phone_number,line;
    int d,m,y;
    getline(file,this->IDStaff,'|');

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

    getline(file,this->CICard,'|');

    getline(file,this->Address,'|');

    getline(file,this->Email,'|');

    file >> this->Wage;

    getline(file,line,'\n');
    return *this;
}

void Staff::SaveNode(ofstream &file) const
{
    file << this->IDStaff;
    file << "|";

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

    file << this->CICard;
    file << "|";

    file << this->Address;
    file << "|";

    file << this->Email;
    file << "|";

    file << this->Wage;
}

istream &operator>>(istream &in,LinkedList<Staff> &S)
{
    string maNV,name,sdt,cccd,diachi,email;
    Day ngaysinh;
    float luong;
    do{
        cout << "Nhap ma nhan vien:";
        in >> maNV;
    } while (S.CheckID(maNV)==true);
    cout << "Nhap ho ten nhan vien:";
    cin.ignore();
    getline(in,name);
    cout << "Nhap so dien thoai:";
    in >> sdt;
    cout << "Nhap ngay sinh:" << endl;
    in >> ngaysinh;
    cout << "Nhap can cuoc cong dan:";
    in >> cccd;
    cout << "Nhap dia chi:";
    cin.ignore();
    getline(in,diachi);
    cout << "Nhap email:";
    in >> email;
    cout << "Nhap he so luong:";
    in >> luong;

    Staff s(maNV,name,sdt,ngaysinh,cccd,diachi,email,luong);
    S.InsertNodeAfter(s);
    return in;
}

void Staff::printfIntro() const
{
    cout << left << setw(15) << "Ma nhan vien";
    cout << left << setw(20) << "Ten nhan vien";
    cout << left << setw(18) << "So dien thoai";
    cout << left << setw(14) << "Nam sinh";
    cout << left << setw(15) << "Can cuoc cd";
    cout << left << setw(30) << "Dia chi";
    cout << left << setw(35) << "Email";
    cout << left << setw(10) << "He so luong";
    cout << endl;
}

void Staff::printfNode() const
{
    cout << left << setw(15) << this->IDStaff;
    cout << left << setw(20) << this->getName();
    cout << left << setw(18) << this->getPhoneNumber();
    cout << this->getNS();
    cout << left << setw(15) << this->CICard;
    cout << left << setw(30) << this->Address;
    cout << left << setw(35) << this->Email;
    cout << left << setw(10) << this->Wage;
    cout << endl;
}
