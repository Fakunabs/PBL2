#ifndef Category_h
#define Category_h

#include <bits/stdc++.h>
#include "LinkedList.h"
#include "Product.h"

using namespace std;

class Category{
    string IDCategory;
    string NameCategory;
public:
    Category(){};
    Category(string IDCategory,string NameCategory);
    Category(const Category &p);
    ~Category(){};
    string getID() const;
    Category ReadNode(ifstream &file);
    void SaveNode(ofstream &file) const;
    friend istream &operator>>(istream &in,LinkedList<Category> &P);
    void DeleteCategory(LinkedList<Category> &C,const LinkedList<Product> &P);
    void printfIntro() const;
    void printfNode() const;
    void printfProductCategory(LinkedList<Product> P,LinkedList<Category> C);
};

#endif // Category_h
