#include "NhanVien.h"
NhanVien::NhanVien(string ms, string ten, double luongcb): ms(ms), ten(ten), luongcb(luongcb) {}
QuanLy::QuanLy(string ms, string ten, double luongcb, double tyLeThuong): NhanVien(ms, ten, luongcb), tyLeThuong(tyLeThuong) {}
KySu::KySu(string ms, string ten, double luongcb, int giolamthem): NhanVien(ms, ten, luongcb), giolamthem(giolamthem) {}

double QuanLy::tienthuong() 
{
    return luongcb*tyLeThuong;
}

void QuanLy::Xuat() 
{
    cout<<"Ma so: "<<ms<<"\n";
    cout<<"Ten: " <<ten<<"\n";
    cout<<"Luong co ban: "<<luongcb<<"\n";
    cout<<"Tien thuong: "<<tienthuong()<<"\n";
}

double KySu::tienthuong() 
{
    return giolamthem*100000;
}

void KySu::Xuat() 
{
    cout<<"Ma so: "<<ms<<"\n";
    cout<<"Ten: "<<ten<<"\n";
    cout<<"Luong co ban: "<<luongcb<<"\n";
    cout<<"Tien thuong: "<<tienthuong() <<"\n";
}
