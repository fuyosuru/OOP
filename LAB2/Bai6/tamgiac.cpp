#include "tamgiac.h"
void TamGiac::Nhap()
{
    //Phương thức nhập toạ độ 3 điểm của một tam giác.
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
    //Phương thức xuất toạ độ 3 điểm của một tam giác.
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
    //Phương thức tịnh tiến toạ độ 3 điểm của một tam giác.
    //Đầu vào: vector tịnh tiến
    A.TinhTien(x,y);
    B.TinhTien(x,y);
    C.TinhTien(x,y);
}
void TamGiac::ThuNho(float k)
{
    //Phương thức thu nhỏ toạ độ 3 điểm của một tam giác.
    //Đầu vào: hệ số thu nhỏ.
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}
void TamGiac::PhongTo(float k)
{
    //Phương thức phóng to toạ độ 3 điểm của một tam giác.
    //Đầu vào: hệ số phóng to.
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}
void TamGiac::Quay(Diem x,float y)
{
    //Phương thức quay toạ độ 3 điểm của một tam giác.
    //Đầu vào: hướng quay và độ.
    A.Quay(x,y);
    B.Quay(x,y);
    C.Quay(x,y);
}
