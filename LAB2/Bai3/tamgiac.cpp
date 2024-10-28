#include "tamgiac.h"
void TamGiac::Nhap()
{
    float x,y;
    std::cout<<"Nhap toa do diem A: ";
    std::cin>>x>>y;
    A=Diem(x,y);
    std::cout<<"Nhap toa do diem B: ";
    std::cin>>x>>y;
    B=Diem(x,y);
    std::cout<<"Nhap toa do diem C: ";
    std::cin>>x>>y;
    C=Diem(x,y);
}
void TamGiac::Xuat()
{
    float x,y;
    std::cout<<"Toa do diem A: ";
    A.Xuat();
    std::cout<<"Toa do diem B: ";
    B.Xuat();
    std::cout<<"Toa do diem C: ";
    C.Xuat();
}
void TamGiac::TinhTien(float x,float y)
{
    A.TinhTien(x,y);
    B.TinhTien(x,y);
    C.TinhTien(x,y);
}
void TamGiac::ThuNho(float k)
{
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}
void TamGiac::PhongTo(float k)
{
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}
void TamGiac::Quay(Diem x,float y)
{
    A.Quay(x,y);
    B.Quay(x,y);
    C.Quay(x,y);
}
