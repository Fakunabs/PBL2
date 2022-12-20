#ifndef Discount_h
#define Discount_h
#include <bits/stdc++.h>

using namespace std;

class Discount{
private:
    float PointRate;
    float DiscountRate;
public:
    Discount(int=0,int=0);
    Discount(const Discount &Ds);
    ~Discount();
    Discount SetDiscount(float x,float y);
    Discount ReadNode(string tenFile);
    void SaveNode(string tenFile) const;
    void printfDiscount() const;
    float getPointRate() const;
    float getDiscountRate() const;
    int CashToPoint(float cash) const;
    float Change(int point) const;
};


#endif // Discount_h
