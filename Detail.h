#ifndef Detail_h
#define Detail_h
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

class Detail{
private:
    string IDReceipt;
    string IDProduct;
    int amount;
    float Price;
public:
    Detail(){};
    Detail(string IDReceipt,string IDProduct,int amount,float Price):
IDReceipt(IDReceipt),IDProduct(IDProduct),amount(amount),Price(Price){};
    ~Detail(){};
    string getID() const;
    string getIDProduct() const;
    int getAmount() const;
    float getPrice() const;
    Detail ReadNode(ifstream &file);
    void SaveNode(ofstream &file) const;
    void printfIntro() const;
    void printfNode() const;
};

#endif // Detail_h

