#include <bits/stdc++.h>
using namespace std;

class SoPhuc{
    private:
        double dThuc,dAo;
    public:
        SoPhuc();
        SoPhuc(double thuc,double ao);
        friend SoPhuc  operator +(SoPhuc b,SoPhuc a);
        friend SoPhuc  operator -(SoPhuc b,SoPhuc a);
        friend SoPhuc  operator *(SoPhuc b,SoPhuc a);
        friend SoPhuc  operator /(SoPhuc b,SoPhuc a);
        friend bool operator ==(SoPhuc b,SoPhuc a);
        friend bool operator !=(SoPhuc b,SoPhuc a);
        friend istream& operator >>(istream &is, SoPhuc &a);
        friend ostream& operator <<(ostream &os, SoPhuc a);
};