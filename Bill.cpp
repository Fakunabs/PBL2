#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Product.h"
#include "Detail.h"
#include "Day.h"
#include "Discount.h"
#include "Bill.h"


using namespace std;

string Bill::getID() const
{
    return this->IDBill;
}

string Bill::getIDMember() const
{
    return this->IDMember;
}

Bill Bill::ReadNode(ifstream &file)
{
    string line;
    int d,m,y;
    getline(file,this->IDBill,'|');

    getline(file,this->IDMember,'|');

    file >> d;
    getline(file,line,'/');
    file >> m;
    getline(file,line,'/');
    file >> y;
    getline(file,line,'|');
    Day D(d,m,y);
    this->BillDay=D;

    getline(file,this->IDStaff,'|');

    file >> this->Point;

    file >> this->DiscountRate;

    getline(file,line,'\n');
    return *this;
}
void Bill::SaveNode(ofstream &file) const
{
    file << this->IDBill;
    file << "|";

    file << this->IDMember;
    file << "|";

    Day D=this->BillDay;

    file << D.getDay();
    file << "/";

    file << D.getMonth();
    file << "/";

    file << D.getYear();
    file << "|";

    file << this->IDStaff;
    file << "|";

    file << this->Point << " " << this->DiscountRate ;
}


long long Bill::Cash(string s,const LinkedList<Detail> &D)
{
    long long t=0;
    Node<Detail> *p=D.getHead();
    Detail node_cur;
    while (p!=NULL)
    {
        node_cur=p->getNode();
        if(node_cur.getID()==s)
        {
            t+=(node_cur.getAmount()*node_cur.getPrice());
        }
        p=p->getNext();
    }
    return t;
}


Bill Bill::CreateBill(string MaNV,LinkedList<Bill> &B,LinkedList<Product> &P,LinkedList<Detail> &Dl,LinkedList<Member> &M,const Discount &Ds)
{
    string maHD,maTV,s;
    int sl,diem=0;
    float mucCK=Ds.getDiscountRate();
    do{
        cout << "Nhap ma hoa don:";
        cin >> maHD;
    }while (B.CheckID(maHD)==true);
    Day D;
    cout << "Ngay nhap hoa don:" << endl;
    cin >> D;

    do {
        do {
            cout << "Nhap ma san pham(nhap 0 de dung):";
            cin >> s;
            if (s=="0") break;
        }while (!P.CheckID(s));
        if (s=="0") break;
        Product p=P.getNode(s); //
        do {
            cout << "Nhap so luong:";
            cin >> sl;
        }while (sl>p.getAmount() || sl<=0);
        p.UpDateAmount(-sl);
        P.UpDateNode(s,p);
        Detail myP(maHD,s,sl,p.getPrice());
        Dl.InsertNodeAfter(myP);
    } while (1);

    do {
        cout << "Nhap ma thanh vien(nhap 0 de thanh toan ngay):" ;
        cin >> maTV;
    }while(maTV!="0" && M.CheckID(maTV)==false);

    Bill tempbill;
    long long t=tempbill.Cash(maHD,Dl);
    cout << "Tong tien:" << t << endl;

    if (maTV=="0")
        diem=0;
    else{
        Member m=M.getNode(maTV);

        cout << "Diem cua ban la:" << m.getPoint() << endl;
        cout << "Muc chiet khau moi diem:" << Ds.getDiscountRate() << endl;
        do {
            cout << "Nhap muc diem quy doi:" ;
            cin >> diem;
        } while (diem<0 || Ds.Change(diem) >= t || diem>m.getPoint());

        m.UpDatePoint(-diem);

        int new_diem=Ds.CashToPoint(t);
        m.UpDatePoint(new_diem);
        M.UpDateNode(maTV,m);
    }

    cout << "Thanh tien:" << t-Ds.Change(diem) << endl;

    Bill b(maHD,maTV,D,MaNV,diem,mucCK);
    B.InsertNodeAfter(b);
    *this=b;
    return *this;
}

void Bill::DeleteBill(LinkedList<Bill> &B,LinkedList<Detail> &D)
{
    string s;
    cout << "Nhsp ma hoa don can xoa:";
    getline(cin,s);
    if (B.CheckID(s)==false)
    {
        cout << "Khong co phan tu de xoa!" << endl;
    } else
    {
        B.DeleteNode(s);
        while(D.CheckID(s)==true)
        {
            D.DeleteNode(s);
        }
        cout << "Xoa thanh cong!" << endl;
    }
}

void Bill::printfIntro() const
{
    cout << left << setw(15) << "Ma hoa don" ;
    cout << left << setw(20) << "Ma thanh vien" ;
    cout << left << setw(14) << "Ngay lap HD" ;
    cout << left << setw(15) << "Ma nhan vien" << endl ;
}
void Bill::printfNode() const
{
    cout << left << setw(15) << this->IDBill ;
    cout << left << setw(20) << this->IDMember;
    cout << this->BillDay;
    cout << left << setw(15) << this->IDStaff << endl;
}

void Bill::printfBillDetail(string s,LinkedList<Bill> B,LinkedList<Detail> Dtl,LinkedList<Product> P)
{
    *this=B.getNode(s);
    cout << char(218);
    for (int i=1;i<50;i++) cout << char(196);
    cout << char(191) << endl;
    cout << char(179) << "Ma hoa don:" << left << setw(15) << this->IDBill << right << setw(24) << char(179) <<endl ;
    cout << char(179) <<"Ngay lap:" << this->BillDay << right << setw(27) << char(179) <<endl;
    cout << char(179) <<"Ma KH:";
    if (this->IDMember=="0") cout << "New User" << right << setw(36)  << char(179) << endl ;
    else cout << left << setw(43) << this->IDMember << char(179) << endl;
    int count=0;
    for (int i=0;i<=50;i++) {
        if (i==0) cout << char(195);
        else if (i==50) cout << char(180) << endl;
        else if (i==4 || i==31 || i==40) cout << char(194) ;
        else cout << char(196);
    }
    Node<Detail> *d=Dtl.getHead();
    cout << char(179) << "STT" << char(179) ;
    cout << "Ten mon an" << right << setw(17) << char(179) ;
    cout << "So luong" << right << setw(1) << char(179) ;
    cout << " Don gia" << right << setw(2) << char(179) << endl ;
    while (d!=NULL)
    {
        Detail detail_cur=d->getNode();
        if (detail_cur.getID()==s)
        {
            cout << char(179) << left << setw(3) << ++count << char(179);
            Product p=P.getNode(detail_cur.getIDProduct());
            cout << left << setw(26) << p.getNameProduct() << char(179);
            cout << right << setw(8) << detail_cur.getAmount() << char(179);
            cout << right << setw(9) << detail_cur.getPrice() << char(179) << endl ;
        }
        d=d->getNext();
    }
    for (int i=0;i<=50;i++) {
        if (i==0) cout << char(195);
        else if (i==50) cout << char(180) << endl;
        else if (i==4 || i==31 || i==40) cout << char(193) ;
        else cout << char(196);
    }
    long long t=this->Cash(s,Dtl);
    cout << char(179) << left << setw(30) << "Thanh tien:" << right << setw(19) << t << char(179) << endl;
    Discount discount;
    discount.SetDiscount(0,this->DiscountRate);
    cout << char(179) << left << setw(30) << "Tien chiet khau:" << right << setw(19) << discount.Change(this->Point) << char(179) << endl;
    cout << char(179) << left << setw(30) << "Tong tien:" << right << setw(19) << t-discount.Change(this->Point) << char(179) << endl;
    for (int i=0;i<=50;i++)
    {
        if (i==0) cout << char(192);
        else if(i==50) cout << char(217);
        else cout << char(196);
    }
}

/*
void Bill::printfBillDetail(string s,LinkedList<Bill> B,LinkedList<Detail> Dtl,LinkedList<Product> P)
{
    *this=B.getNode(s);
    cout << "Ma hoa don:" << left << setw(15) << this->IDBill << endl ;
    cout << "Ngay lap:" << this->BillDay << endl;
    cout << "Ma KH:";
    if (this->IDMember=="0") cout << "New User" << endl;
    else cout << this->IDMember << endl;
    int count=0;
    Node<Detail> *d=Dtl.getHead();
    cout << "STT" << endl;
    while (d!=NULL)
    {
        Detail detail_cur=d->getNode();
        if (detail_cur.getID()==s)
        {
            cout << left << setw(5) << ++count;
            Product p=P.getNode(detail_cur.getIDProduct());
            cout << left << setw(30) << p.getNameProduct();
            cout << left << setw(8) << detail_cur.getAmount();
            cout << right << setw(10) << detail_cur.getPrice() << endl ;
        }
        d=d->getNext();
    }
    int t=this->Cash(s,Dtl);
    cout << left << setw(20) << "Thanh tien:" << right << setw(15) << t << endl;
    Discount discount;
    discount.SetDiscount(0,this->DiscountRate);
    cout << left << setw(20) << "Tien chiet khau:" << right << setw(15) << discount.Change(this->Point) << endl;
    cout << left << setw(20) << "Tong tien:" << right << setw(15) << t-discount.Change(this->Point) << endl;
}
*/

void Bill::printfHistoryBill(string s,const LinkedList<Bill> &B)
{
    Node<Bill> *b=B.getHead();
    while (b!=NULL)
    {
        *this=b->getNode();
        if(this->getIDMember()==s)
        {
            this->printfNode();
        }
        b=b->getNext();
    }
}

void Bill::printfRevenue(LinkedList<Bill> B,LinkedList<Detail> Dtl,LinkedList<Product> P)
{
    Day Dstar,Dfinish;
    cout << "Nhap ngay bat dau:\n";
    cin >> Dstar;
    cout << "Nhap ngay ket thuc:\n";
    cin >> Dfinish;
    if (Dfinish<=Dstar)
    {
        cout << "Ngay nhap vao khong hop le!\n";
        return ;
    }
    long long Sum=0;
    Node<Bill> *b=B.getHead();
    cout << left << setw(15) << "Ma hoa don" ;
    cout << left << setw(20) << "Ma thanh vien" ;
    cout << left << setw(14) << "Ngay lap HD" ;
    cout << left << setw(12) << "Ma nhan vien";
    cout << right << setw(13) << "Thanh tien" << endl;
    while (b!=NULL)
    {
        *this=b->getNode();
        if(this->BillDay<=Dfinish && Dstar<=this->BillDay)
        {
            cout << left << setw(15) << this->IDBill ;
            cout << left << setw(20) << this->IDMember;
            cout << this->BillDay;
            cout << left << setw(15) << this->IDStaff;
            long long t=this->Cash(this->getID(),Dtl);
            Sum+=t;
            cout << left << setw(15) << t << endl;
        }
        b=b->getNext();
    }
    cout << "Tong doanh thu tu " << Dstar << " den " << Dfinish << " la:";
    cout << Sum << endl;
}