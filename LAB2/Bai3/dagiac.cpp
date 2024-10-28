#include "dagiac.h"

void DaGiac::Nhap()
{
    //Phương thức nhập thông tin các điểm của một đa giác.
    std::cout<<"Nhap so dinh cua da giac: ";
    std::cin>>n;
    Dinh = new Diem[n];
    for(int i=0;i<n;i++)
    {
        std::cout<<"Nhap toa do cua diem thu "<<i+1<<": ";
        float x,y;
        std::cin>>x>>y;
        Dinh[i]=Diem(x,y);
    }
}
void DaGiac::Xuat()
{
    //Phương thức xuất thông tin các điểm của một đa giác.
    std::cout<<"Cac dinh cua da giac: \n";
    for(int i=0;i<n;i++)
    {
        std::cout<<"Toa do cua diem thu "<<i+1<<": ";
        Dinh[i].Xuat();
    }
}
void DaGiac::TinhTien(float x,float y)
{
    //Đầu vào: vector tịnh tiến.
    //Phương thức tịnh tiến các điểm của một đa giác.
    for(int i=0;i<n;i++)
        Dinh[i].TinhTien(x,y);
}
void DaGiac::PhongTo(float x)
{
    //Đầu vào: hệ số phóng to.
    //Phương thức phóng to các điểm của một đa giác.
    for(int i=0;i<n;i++)
        Dinh[i].PhongTo(x);
}
void DaGiac::ThuNho(float x)
{
    //Đầu vào: hệ số thu nhỏ.
    //Phương thức thu nhỏ các điểm của một đa giác.
    for(int i=0;i<n;i++)
        Dinh[i].ThuNho(x);
}
void DaGiac::Quay(Diem x,float y)
{
    //Đầu vào: hướng quay (diem) và góc quay (độ).
    //Phương thức quay các điểm của một đa giác.
    for(int i=0;i<n;i++)
        Dinh[i].Quay(x,y);
}
