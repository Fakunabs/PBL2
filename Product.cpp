#include <bits/stdc++.h>
#include "Product.h"
#include "Staff.h"
#include "Member.h"
#include "Detail.h"
#include "Day.h"
#include "Discount.h"

using namespace std;

Product::Product(string IDProduct,string NameProduct,string IDCategory,int amount,float Price)
{
    this->IDProduct=IDProduct;
    this->NameProduct=NameProduct;
    this->IDCategory=IDCategory;
    this->amount=amount;
    this->Price=Price;
}

Product::Product(const Product &p)
{
    this->IDProduct=p.IDProduct;
    this->NameProduct=p.NameProduct;
    this->IDCategory=p.IDCategory;
    this->amount=p.amount;
    this->Price=p.Price;
}

string Product::getID()const
{
    return this->IDProduct;
}

string Product::getIDCategory() const
{
    return this->IDCategory;
}

string Product::getNameProduct() const
{
    return this->NameProduct;
}

int Product::getAmount() const
{
    return this->amount;
}

float Product::getPrice() const
{
    return this->Price;
}

void Product::UpDateAmount(int amount)
{
    this->amount+=amount;
}

void Product::UpDatePrice(int price)
{
    this->Price=price;
}

Product Product::ReadNode(ifstream &file)
{
    string line;
    getline(file,this->IDProduct,'|');

    getline(file,this->NameProduct,'|');

    getline(file,this->IDCategory,'|');

    file >> this->amount;

    file >> this->Price;
    getline(file,line,'\n');
    return *this;
}

void Product::SaveNode(ofstream &file) const
{
    file << this->IDProduct;
    file << "|";
    file << this->NameProduct;
    file << "|";
    file << this->IDCategory;
    file << "|";
    file << this->amount << " " << this->Price;
}

istream &operator>>(istream &in,LinkedList<Product> &P)
{
    string s1,s2,s3;
    int sl;
    float dongia;
    do {
        cout << "Nhap ma san pham:";
        getline(cin,s1);
    } while (P.CheckID(s1)==true);
    cout << "Nhap ten san pham:";
    getline(cin,s2);
    do {
        cout << "Nhap ma loai:";
        getline(cin,s3);
    } while (P.CheckID(s3)==true);

    cout << "Nhap so luong:";
    in >> sl;
    cout << "Nhap don gia:";
    in >> dongia;
    Product p(s1,s2,s3,sl,dongia);
    P.InsertNodeAfter(p);
    return in;
}

void Product::DeleteProduct(LinkedList<Product> &P,const LinkedList<Detail> &D)
{
    string s;
    cout << "Nhap ma san pham can xoa:";
    getline(cin,s);
    if (P.CheckID(s)==false)
    {
        cout << "Khong co phan tu de xoa!" << endl;
    } else
    {
        Node<Detail> *p=D.getHead();
        while(p!=NULL)
        {
            Detail detail_cur=p->getNode();
            if (detail_cur.getID()==s)
            {
                cout << "Khong the xoa!\n";
                return;
            }
            p=p->getNext();
        }
        P.DeleteNode(s);
        cout << "Xoa thanh cong!\n";
    }
}

void Product::printfIntro() const
{
    cout << left << setw(10) << "Ma SP";
    cout << left << setw(30) << "Ten SP";
    cout << left << setw(10) << "Ma Loai";
    cout << left << setw(10) << "So Luong";
    cout << left << setw(10) << "Don gia";
    cout << endl;
}

void Product::printfNode() const
{
    cout << left << setw(10) << this->IDProduct ;
    cout << left << setw(30) << this->NameProduct;
    cout << left << setw(10) << this->IDCategory ;
    cout << left << setw(10) << this->amount;
    cout << left << setw(10) << this->Price;
    cout << endl;

}

void Product::EditAmount(string s,LinkedList<Product> &P)
{
    int amount;
    do{
        cout << "Nhap so luong them vao:";
        cin >> amount;
    } while (amount<0);
    Node<Product> *p=P.getHead();
    Product node_cur;
    while (p!=NULL)
    {
        node_cur=p->getNode();
        if(node_cur.getID()==s)
        {
            node_cur.UpDateAmount(amount);
            break;
        }
        p=p->getNext();
    }
    P.UpDateNode(s,node_cur);
}

void Product::EditPrice(string s,LinkedList<Product> &P)
{
    int price;
    do{
        cout << "Nhap don gia moi:";
        cin >> price;
    } while (price<0);
    Node<Product> *p=P.getHead();
    Product node_cur;
    while (p!=NULL)
    {
        node_cur=p->getNode();
        if(node_cur.getID()==s)
        {
            node_cur.UpDatePrice(price);
            break;
        }
        p=p->getNext();
    }
    P.UpDateNode(s,node_cur);
}

