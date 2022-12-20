#include <bits/stdc++.h>
#include "Detail.h"

using namespace std;
string Detail::getID() const
{
    return this->IDReceipt;
}
string Detail::getIDProduct() const
{
    return this->IDProduct;
}
int Detail::getAmount() const
{
    return this->amount;
}
float Detail::getPrice() const
{
    return this->Price;
}


Detail Detail::ReadNode(ifstream &file)
{
    string line;

    getline(file,this->IDReceipt,'|');

    getline(file,this->IDProduct,'|');

    file >> this->amount;

    file >> this->Price;
    getline(file,line,'\n');
    return *this;
}

void Detail::SaveNode(ofstream &file) const
{
    file << this->IDReceipt;
    file << "|";
    file << this->IDProduct;
    file << "|";
    file << this->amount << " " << this->Price;
}

void Detail::printfIntro() const
{

}
void Detail::printfNode() const
{
    cout << left << setw(10) << this->IDReceipt;
    cout << left << setw(30) << this->IDProduct;
    cout << left << setw(10) << this->amount;
    cout << left << setw(10) << this->Price;
    cout << endl;
}

