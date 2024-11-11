#include <bits/stdc++.h>
using namespace std;

class NgayThangNam{
    private:
        int iNgay,iThang,iNam;
    public:
        NgayThangNam();
        NgayThangNam(int Ngay,int Thang,int Nam);
        int TinhNgay();
        NgayThangNam  operator -(NgayThangNam b);
        NgayThangNam  operator +(int Giay);
        NgayThangNam  operator -(int Giay);
        NgayThangNam operator ++();
        NgayThangNam operator ++(int a);
        NgayThangNam operator --();
        NgayThangNam operator --(int a);
        bool operator ==(NgayThangNam b);
        bool operator !=(NgayThangNam b);
        bool operator >=(NgayThangNam b);
        bool operator <=(NgayThangNam b);
        bool operator >(NgayThangNam b);
        bool operator <(NgayThangNam b);
        friend istream& operator >>(istream &is, NgayThangNam &a);
        friend ostream& operator <<(ostream &os, NgayThangNam a);
};