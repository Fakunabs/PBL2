#ifndef Product_h
#define Product_h

#include <bits/stdc++.h>
#include "Staff.h"
#include "Member.h"
#include "Detail.h"
#include "Day.h"
#include "Discount.h"
#include "LinkedList.h"

using namespace std;


class Product{
    string IDProduct;
    string NameProduct;
    string IDCategory;
    int amount; // so luong san pham
    float Price; // don gia 1 san pham
public:
    Product(){};
    Product(string IDProduct,string NameProduct,string IDCategory,int amount,float Price);
    Product(const Product &p);
    ~Product(){};
    string getID() const;
    string getIDCategory() const;
    string getNameProduct() const;
    int getAmount() const;
    float getPrice() const;
    void UpDateAmount(int amount);
    void UpDatePrice(int price);
    Product ReadNode(ifstream &file);
    void SaveNode(ofstream &file) const;
    friend istream &operator>>(istream &in,LinkedList<Product> &P);
    void DeleteProduct(LinkedList<Product> &P,const LinkedList<Detail> &D);
    void printfIntro() const;
    void printfNode() const;
    void EditAmount(string s,LinkedList<Product> &P);
    void EditPrice(string s,LinkedList<Product> &P);
};

#endif // Product_h
