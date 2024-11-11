#include <bits/stdc++.h>
using namespace std;

class PhanSo{
    private:
        int iTu,iMau;
    public:
        PhanSo();
        PhanSo(int Tu,int Mau);
        PhanSo(double x);
        friend PhanSo operator +(PhanSo b, PhanSo a);
        friend PhanSo operator -(PhanSo b, PhanSo a);
        friend PhanSo operator *(PhanSo b, PhanSo a);
        friend PhanSo operator /(PhanSo b, PhanSo a);
        friend bool operator ==(PhanSo b, PhanSo a);
        friend bool operator !=(PhanSo b, PhanSo a);
        friend bool operator >=(PhanSo b, PhanSo a);
        friend bool operator <=(PhanSo b, PhanSo a);
        friend bool operator >(PhanSo b, PhanSo a);
        friend bool operator <(PhanSo b, PhanSo a);
        friend istream& operator >>(istream &is, PhanSo &a);
        friend ostream& operator <<(ostream &os, PhanSo a);
};