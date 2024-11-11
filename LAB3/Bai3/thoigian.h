#include <bits/stdc++.h>
using namespace std;

class ThoiGian{
    private:
        int iGio, iPhut, iGiay;
    public:
        ThoiGian();
        ThoiGian(int Gio, int Phut, int Giay);
        int TinhGiay();
        ThoiGian TinhLaiGio(int Giay);
        ThoiGian  operator +(ThoiGian b);
        ThoiGian  operator -(ThoiGian b);
        ThoiGian  operator +(int Giay);
        ThoiGian  operator -(int Giay);
        ThoiGian operator ++();
        ThoiGian operator ++(int a);
        ThoiGian operator --();
        ThoiGian operator --(int a);
        bool operator ==(ThoiGian b);
        bool operator !=(ThoiGian b);
        bool operator >=(ThoiGian b);
        bool operator <=(ThoiGian b);
        bool operator >(ThoiGian b);
        bool operator <(ThoiGian b);
        friend istream& operator >>(istream &is, ThoiGian &a);
        friend ostream& operator <<(ostream &os, ThoiGian a);
};