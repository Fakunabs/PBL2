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

void setspace(int n)
{
    while (n--)
        cout << " " ;
}

void Intro_start()
{
    SetColor(2);
    int n=80;
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        cout << char(196);
    cout << endl;
    setspace(5 + n);
    cout << "Truong Dai hoc Bach Khoa - Dai hoc Da Nang" << endl;
    setspace(14 + n);
    cout << "Khoa Cong nghe thong tin" << endl;
    setspace(24 + n);
    cout << "*---*" << endl ;
    setspace(11 + n);
    cout << "PBL2: Du an co so lap trinh" << endl;
    setspace(9 + n);
    cout << "De tai:Quan ly cua hang thuc an nhanh\n\n\n" ;
    setspace(n);
    cout << "Sinh vien thuc hien:" ;
    setspace(10);
    cout << "Giang vien huong dan:\n" ;
    setspace(n);
    cout << "-Nguyen Xuan Thinh" ;
    setspace(12);
    cout << "-Le Thi My Hanh\n" ;
    setspace(n);
    cout << "-Tran Huu Tuan\n" ;
    setspace(n - 5);
    for (int i = 0; i < 60; i++)
        cout << char(196);
    SetColor(7);
    getchar();
    system("cls");
}

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
    Intro_start();
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
        choose=Menu(80,5,35,2,11,75,nd,n);
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
    nd[0]="Chuc nang xem";
    nd[1]="Chuc nang them";
    nd[2]="Chuc nang cap nhat thong tin";
    nd[3]="Chuc nang xoa";
    nd[4]="Thoat";
    do
    {
        system("cls");
        choose=Menu(80,5,35,2,11,75,nd,n);
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
        choose=Menu(80,5,35,2,11,75,nd,n);
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
        choose=Menu(80,5,35,2,11,75,nd,n);
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
        choose=Menu(80,5,35,2,11,75,nd,n);
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
        choose=Menu(80,5,35,2,11,75,nd,n);
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
        choose=Menu(80,5,35,2,11,75,nd,2);
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
        choose=Menu(80,5,35,2,11,75,nd,n);
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