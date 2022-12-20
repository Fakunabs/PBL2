#ifndef Bill_h
#define Bill_h
#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Product.h"
#include "Detail.h"
#include "Day.h"
#include "Discount.h"
#include "LinkedList.h"

using namespace std;

class Bill{
private:
    string IDBill;
    string IDMember;
    Day BillDay;
    string IDStaff;
    int Point;
    float DiscountRate;
public:
    Bill(){};
    Bill(string IDBill,string IDMember,Day D,string IDStaff,int Point,float DiscountRate):
IDBill(IDBill),IDMember(IDMember),BillDay(D),IDStaff(IDStaff),Point(Point),DiscountRate(DiscountRate){};
    ~Bill(){};
    string getID() const;
    string getIDMember() const;
    float Cash(string s,const LinkedList<Detail> &D);
    Bill CreateBill(string MaNV,LinkedList<Bill> &,LinkedList<Product> &P,LinkedList<Detail> &MyP,LinkedList<Member> &M,const Discount &Ds);
    void DeleteBill(LinkedList<Bill> &B,LinkedList<Detail> &D);
    Bill ReadNode(ifstream &file);
    void SaveNode(ofstream &file) const;
    void printfIntro() const;
    void printfNode() const;
    void printfBillDetail(string s,LinkedList<Bill> B,LinkedList<Detail> Dtl,LinkedList<Product> P);
    void printfHistoryBill(string s,const LinkedList<Bill> &B);
    void printfRevenue(LinkedList<Bill> B,LinkedList<Detail> Dtl,LinkedList<Product> P);
};


#endif // Bill_h

