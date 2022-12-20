#include <bits/stdc++.h>
#include "Category.h"
#include "Product.h"

using namespace std;


Category::Category(string IDCategory,string NameCategory)
{
    this->IDCategory=IDCategory;
    this->NameCategory=NameCategory;
}

Category::Category(const Category &p)
{
    this->IDCategory=p.IDCategory;
    this->NameCategory=p.NameCategory;
}


string Category::getID() const
{
    return this->IDCategory;
}

Category Category::ReadNode(ifstream &file)
{
    string line;
    getline(file,this->IDCategory,'|');

    getline(file,this->NameCategory,'|');

    getline(file,line,'\n');

    return *this;
}

void Category::SaveNode(ofstream &file) const
{
    file << this->IDCategory;
    file << "|";
    file << this->NameCategory;
    file << "|";
}

istream &operator>>(istream &in,LinkedList<Category> &C)
{
    string s1,s2;
    do {
        cout << "Nhap ma loai:";
        getline(cin,s1);
    } while (C.CheckID(s1)==true);
    cout << "Nhap ten loai:";
    getline(cin,s2);

    Category c(s1,s2);
    C.InsertNodeAfter(c);
    return in;
}

void Category::DeleteCategory(LinkedList<Category> &C,const LinkedList<Product> &P)
{
    string s;
    cout << "Nhap ma loai san pham can xoa:";
    getline(cin,s);
    if (C.CheckID(s)==false)
    {
        cout << "Khong co phan tu de xoa!" << endl;
    } else
    {
        Node<Product> *p=P.getHead();
        while(p!=NULL)
        {
            Product detail_cur=p->getNode();
            if (detail_cur.getIDCategory()==s)
            {
                cout << "Khong the xoa!\n";
                return;
            }
            p=p->getNext();
        }
        C.DeleteNode(s);
        cout << "Xoa thanh cong!\n";
    }
}

void Category::printfIntro() const
{
    cout << left << setw(10) << "Ma loai";
    cout << left << setw(30) << "Ten loai";
    cout << endl;
}

void Category::printfNode() const
{
    cout << left << setw(10) << this->IDCategory ;
    cout << left << setw(30) << this->NameCategory;
    cout << endl;
}

void Category::printfProductCategory(LinkedList<Product> P,LinkedList<Category> C)
{
    Node<Category> *c=C.getHead();
    Category node_cur;
    while (c!=NULL)
    {
        node_cur=c->getNode();
        cout << node_cur.NameCategory << endl;
        Node<Product> *p=P.getHead();
        while (p!=NULL)
        {
            Product product_cur=p->getNode();
            if(node_cur.getID()==product_cur.getIDCategory())
            {
                product_cur.printfNode();
            }
            p=p->getNext();
        }
        c=c->getNext();
        cout << endl << endl;
    }
}
