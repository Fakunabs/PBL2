#include <bits/stdc++.h>
#include "Discount.h"


Discount::Discount(int x,int y)
{
    this->PointRate=x;
    this->DiscountRate=y;
}

Discount::Discount(const Discount &Ds)
{
    this->PointRate=Ds.PointRate;
    this->DiscountRate=Ds.DiscountRate;
}

Discount::~Discount()
{

}

Discount Discount::SetDiscount(float x,float y)
{
    this->PointRate=x;
    this->DiscountRate=y;
    return *this;
}

Discount Discount::ReadNode(string TenFile)
{
    ifstream input_File;
    input_File.open(TenFile,ios::in);
    input_File >> this->PointRate;
    input_File >> this->DiscountRate;
    input_File.close();
    return *this;
}

void Discount::SaveNode(string TenFile) const
{
    ofstream output_File;
    output_File.open(TenFile,ios::out | ios::trunc);
    output_File << this->PointRate << " ";
    output_File << this->DiscountRate;
    output_File.close();
}

void Discount::printfDiscount() const
{
    cout << this->PointRate << " ";
    cout << this->DiscountRate << endl;
}

float Discount::getPointRate() const
{
    return this->PointRate;
}

float Discount::getDiscountRate() const
{
    return this->DiscountRate;
}

int Discount::CashToPoint(float cash) const
{
    return cash*(this->getPointRate());
}

float Discount::Change(int point) const
{
    return point*(this->getDiscountRate());
}

