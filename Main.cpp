#include <bits/stdc++.h>
#include "LinkedList.h"
#include "Product.h"
#include "Day.h"
#include "Person.h"
#include "Staff.h"
#include "Member.h"
#include "Detail.h"
#include "Discount.h"
#include "Bill.h"
#include "Category.h"
#include "MyLib.h"
#include "MyMenu.h"

using namespace std;

void GetData(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void Menu(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void QuanLyCuaHang(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void Xem(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void Them(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void CapNhat(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void Xoa(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void ChucNangNhapXuatHoaDon(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void ChucNangKhachHang(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D);
void SaveData(const LinkedList<Product> &P,const LinkedList<Staff> &S,const LinkedList<Member> &M,const LinkedList<Bill> &B,const LinkedList<Detail> &Dtl,const LinkedList<Category> &C,const Discount &D);

int main()
{
    LinkedList<Product> P;
    LinkedList<Staff> S;
    LinkedList<Member> M;
    LinkedList<Bill> B;
    LinkedList<Detail> Dtl;
    LinkedList<Category> C;
    Discount D;
    GetData(P,S,M,B,Dtl,C,D);
    Menu(P,S,M,B,Dtl,C,D);
    SaveData(P,S,M,B,Dtl,C,D);
    return 0;
}

void Menu(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Category c;
    int choose,n=4;
    string nd[n];
    nd[0]="Quan ly cua hang";
    nd[1]="Chuc nang nhap xuat hoa don";
    nd[2]="Chuc nang khach hang";
    nd[3]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        system("cls");
        switch(choose)
        {
        case 0:
            QuanLyCuaHang(P,S,M,B,Dtl,C,D);
            break;
        case 1:
            ChucNangNhapXuatHoaDon(P,S,M,B,Dtl,C,D);
            break;
        case 2:
            ChucNangKhachHang(P,S,M,B,Dtl,C,D);
            break;
        case 3:
            system("pause");
            break;
        }
    } while (n-choose-1);
}

void QuanLyCuaHang(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Category c;
    int choose,n=5;
    string nd[n];
    nd[0]="Xem...";
    nd[1]="Them...";
    nd[2]="Cap nhat...";
    nd[3]="Xoa...";
    nd[4]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        system("cls");
        switch(choose)
        {
        case 0:
            Xem(P,S,M,B,Dtl,C,D);
            break;
        case 1:
            Them(P,S,M,B,Dtl,C,D);
            break;
        case 2:
            CapNhat(P,S,M,B,Dtl,C,D);
            break;
        case 3:
            Xoa(P,S,M,B,Dtl,C,D);
            break;
        case 4:
            break;
        }
    } while (n-choose-1);
}

void Xem(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Category c;
    int choose,n=8;
    string nd[n],s;
    nd[0]="Xem san pham";
    nd[1]="Xem cac loai san pham";
    nd[2]="Xem danh sach hoa don";
    nd[3]="Xem chi tiet 1 hoa don";
    nd[4]="Xem doanh thu";
    nd[5]="Xem danh sach nhan vien";
    nd[6]="Xem danh sach cac thanh vien";
    nd[7]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        switch(choose)
        {
        case 0:
            system("cls");
            c.printfProductCategory(P,C);
            system("pause");
            break;
        case 1:
            system("cls");
            C.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 2:
            system("cls");
            B.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 3:
            system("cls");
            B.printfList();
            cout << "Nhap ma hoa don:";
            cin >> s;
            if (B.CheckID(s)==false) cout << "\n\n=>Khong co trong danh sach!";
            else
            {
                cout << "\n\n";
                b.printfBillDetail(s,B,Dtl,P);
            }
            cout << "\n\n";
            system("pause");
            break;
        case 4:
            system("cls");
            b.printfRevenue(B,Dtl,P);
            system("pause");
            break;
        case 5:
            system("cls");
            S.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 6:
            system("cls");
            M.printfList();
            cout << "\n\n";
            system("pause");
            break;
        case 7:
            break;
        }
    } while (n-choose-1);
}
void Them(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Category c;
    int choose,n=4;
    string nd[n];
    nd[0]="Them san pham";
    nd[1]="Them loai san pham";
    nd[2]="Them nhan vien";
    nd[3]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        switch(choose)
        {
        case 0:
            system("cls");
            P.printfList();
            cout << "\n\n";
            cin >> P;
            system("pause");
            break;
        case 1:
            system("cls");
            C.printfList();
            cout << "\n\n";
            cin >> C;
            system("pause");
            break;
        case 2:
            system("cls");
            S.printfList();
            cout << "\n\n";
            cin >> S;
            system("pause");
            break;
        case 3:
            break;
        }
    } while (n-choose-1);
}
void CapNhat(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    float x,y;
    Product p;
    Bill b;
    Category c;
    int choose,n=4;
    string nd[n],s;
    nd[0]="Cap nhat so luong san pham";
    nd[1]="Cap nhat don gia san pham";
    nd[2]="Cap nhat muc chiet khau";
    nd[3]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        switch(choose)
        {
        case 0:
            system("cls");
            P.printfList();
            cout << "\n\n";
            do {
                cout << "Nhap ma san pham:";
                getline(cin,s);
            } while (P.CheckID(s)==false);
            p.EditAmount(s,P);
            system("pause");
            break;
        case 1:
            system("cls");
            P.printfList();
            cout << "\n\n";
            do {
                cout << "Nhap ma san pham:";
                getline(cin,s);
            } while (P.CheckID(s)==false);
            p.EditPrice(s,P);
            system("pause");
            break;
        case 2:
            system("cls");
            D.printfDiscount();
            cout << "\n\n";
            cout << "Nhap muc quy doi ve diem:";
            cin >> x;
            cout << "Nhap muc chiet khau moi diem:";
            cin >> y;
            D.SetDiscount(x,y);
            system("pause");
            break;
        case 3:
            break;
        }
    } while (n-choose-1);
}
void Xoa(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Product p;
    Category c;
    int choose,n=4;
    string nd[n];
    nd[0]="Xoa 1 san pham";
    nd[1]="Xoa 1 loai san pham";
    nd[2]="Xoa 1 hoa don";
    nd[3]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        switch(choose)
        {
        case 0:
            system("cls");
            P.printfList();
            cout << "\n\n";
            p.DeleteProduct(P,Dtl);
            system("pause");
            Xem(P,S,M,B,Dtl,C,D);
            break;
        case 1:
            system("cls");
            C.printfList();
            cout << "\n\n";
            c.DeleteCategory(C,P);
            system("pause");
            break;
        case 2:
            system("cls");
            B.printfList();
            cout << "\n\n";
            b.DeleteBill(B,Dtl);
            system("pause");
            break;
        case 3:
            break;
        }
    } while (n-choose-1);
}

void ChucNangNhapXuatHoaDon(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Category c;
    int choose,n=2;
    string nd[n];
    nd[0]="Nhap hoa don";
    nd[1]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,2);
        switch(choose)
        {
        case 0:
            system("cls");
            c.printfProductCategory(P,C);
            cout << "\n\nTao hoa don:\n";
            b.CreateBill("NV01",B,P,Dtl,M,D);
            system("pause");
            break;
        case 1:
            break;
        }
    } while (n-choose-1);
}

void ChucNangKhachHang(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    Bill b;
    Category c;
    int choose,n=4;
    string nd[n],s;
    nd[0]="Dang ky thanh vien";
    nd[1]="Xem lich su giao dich";
    nd[2]="Xem chi tiet hoa don da giao dich";
    nd[3]="Thoat";
    do
    {
        system("cls");
        choose=Menu(50,5,35,2,11,75,nd,n);
        system("cls");
        switch(choose)
        {
        case 0:
            cout << "Tao tai khoan thanh vien:\n\n";
            cin >> M;
            system("pause");
            break;
        case 1:
            cout << "Nhap so dien thoai (ma thanh vien):";
            cin >> s;
            b.printfHistoryBill(s,B);
            system("pause");
            break;
        case 2:
            cout << "Nhap so dien thoai (ma thanh vien):";
            cin >> s;
            b.printfHistoryBill(s,B);
            cout << "Nhap ma hoa don can xem chi tiet:";
            cin >> s;
            if (B.CheckID(s)==false) cout << "\n\n=>Khong co trong danh sach!";
            else
            {
                cout << "\n\n";
                b.printfBillDetail(s,B,Dtl,P);
            }
            cout << "\n\n";
            system("pause");
            break;
        case 3:
            break;
        }
    } while (n-choose-1);
}

void GetData(LinkedList<Product> &P,LinkedList<Staff> &S,LinkedList<Member> &M,LinkedList<Bill> &B,LinkedList<Detail> &Dtl,LinkedList<Category> &C,Discount &D)
{
    P.ReadDataFromFile("Product.txt");
    S.ReadDataFromFile("Staff.txt");
    M.ReadDataFromFile("Member.txt");
    B.ReadDataFromFile("Bill.txt");
    Dtl.ReadDataFromFile("Detail.txt");
    C.ReadDataFromFile("Category.txt");
    D.ReadNode("Discount.txt");
}


void SaveData(const LinkedList<Product> &P,const LinkedList<Staff> &S,const LinkedList<Member> &M,const LinkedList<Bill> &B,const LinkedList<Detail> &Dtl,const LinkedList<Category> &C,const Discount &D)
{
    P.SavaDataToFile("Product.txt");
    S.SavaDataToFile("Staff.txt");
    M.SavaDataToFile("Member.txt");
    B.SavaDataToFile("Bill.txt");
    Dtl.SavaDataToFile("Detail.txt");
    C.SavaDataToFile("Category.txt");
    D.SaveNode("Discount.txt");
}
