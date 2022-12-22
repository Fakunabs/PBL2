#ifndef MyMenu_h
#define MyMenu_h

#include<bits/stdc++.h>
#include <windows.h>
#include "MyLib.h"

using namespace std;

void thanh_sang(int x,int y,int w,int h,int b_color,string nd);
void box(int x,int y,int w,int h,int t_color,int b_color,string nd);
void MulBox(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n);
int Menu(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n);


int Menu(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n)
{
    ShowCur(0);
    MulBox(x,y,w,h,t_color,b_color,nd,n);

    int posbefore=0,pos=0;
    int xpoint=x,ypoint=y;
    int xbefore=x,ybefore=y;
    bool check=false;

    thanh_sang(xpoint,ypoint,w,h,4,nd[pos]);
    while (true)
    {
        if (check==true)
        {
            gotoXY(xbefore,ybefore);
            thanh_sang(xbefore,ybefore,w,h,b_color,nd[posbefore]);
            thanh_sang(xpoint,ypoint,w,h,4,nd[pos]);
            check=false;
        }
        if (_kbhit())
        {
            char c=_getch();
            if (c==13) break;
            if (c==-32)
            {
                check=true;
                c=_getch();
                ybefore=ypoint;
                posbefore=pos;
                if (c==72)
                {
                    if (ypoint!=y) {
                        ypoint-=h;
                        pos--;
                    }
                    else {
                        pos=n-1;
                        ypoint = y+h*(n-1);
                    }
                }
                if(c==80)
                {
                    if (ypoint != y+h*(n-1)) {
                        ypoint+=h;
                        pos++;
                    }
                    else {
                        pos=0;
                        ypoint=y;
                    }
                }
            }
        }
    }
    SetColor(7);
    ShowCur(1);
    return pos;
}

void thanh_sang(int x,int y,int w,int h,int b_color,string nd)
{
    SetColor(b_color);
    for (int i=x+1;i<x+w;i++)
    {
        for(int j=y+1;j<y+h;j++)
        {
            gotoXY(i,j);cout << " ";
        }
    }
    SetColor(b_color);
    gotoXY(x+1,y+1);
    cout << nd;
}

void box(int x,int y,int w,int h,int t_color,int b_color,string nd)
{
    SetColor(b_color);
    for (int i=x;i<=x+w;i++)
    {
        for(int j=y;j<=y+h;j++)
        {
            gotoXY(i,j);cout << " ";
        }
    }
    SetColor(t_color);
    gotoXY(x+1,y+1);
    cout << nd;
    SetColor(b_color%t_color);
    if (h<=1 || w<=1) return;
    for(int i=x;i<=x+w;i++)
    {
        gotoXY(i,y);
        cout << char(196);
        gotoXY(i,y+h);
        cout << char(196);
    }
    for (int i=y;i<=y+h;i++)
    {
        gotoXY(x,i);
        cout << char(179);
        gotoXY(x+w,i);
        cout << char(179);
    }
    gotoXY(x,y);cout << char(218);
    gotoXY(x+w,y);cout << char(191);
    gotoXY(x,y+h);cout << char(192);
    gotoXY(x+w,y+h);cout << char(217);
}

void MulBox(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n)
{
    for (int i=0;i<n;i++)
    {
        box(x,y+h*i,w,h,t_color,b_color,nd[i]);
        if(i!=0)
        {
            gotoXY(x,y+h*i); cout << char(195);
            gotoXY(x+w,y+h*i); cout << char(180);
        }
    }
}


#endif // MyMenu_h