#include <bits/stdc++.h>
using namespace std;
class NhanVien{
protected:
    string ms;
    string ten;
    double luongcb;
public:
    NhanVien(string ms, string ten, double luongcb);
};

class QuanLy:public NhanVien {
private:
    double tyLeThuong;
public:
    QuanLy(string ms, string ten, double luongcb, double tyLeThuong);
    double tienthuong();
    void Xuat();
};

class KySu:public NhanVien{
private:
    int giolamthem;
public:
    KySu(string ms,string ten, double luongcb, int giolamthem);
    double tienthuong();
    void Xuat();
};
