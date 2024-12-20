
#include "diem.h"
#include<bits/stdc++.h>
Diem::Diem()
{
    //Constructor mặc định của class điểm.
    iHoanh=0;
    iTung=0;    
}
Diem::Diem(float Hoanh,float Tung)
{
    //Constructor của class điểm sẽ tạo ra biến điểm dựa trên toạ độ được truyền vào.
    iHoanh=Hoanh;
    iTung=Tung;
}
Diem::Diem(const Diem &x)
{
    //Copy constructor của class điểm.
    iHoanh=x.iHoanh;
    iTung=x.iTung;
}
void Diem::Xuat()
{
    //Phương thức xuất thông tin của một điểm.
    printf("(%f,%f)\n",iHoanh,iTung);
}
float Diem::GetTungDo()
{
    //Phương thức trả về tung độ của một điểm.
    //Đầu ra: tung độ của điểm.
    return iTung;
}
float Diem::GetHoanhDo()
{
    //Phương thức trả về hoành độ của một điểm.
    //Đầu ra: hoành độ của điểm.
    return iHoanh;
}
void Diem::SetHoanhDo(float x)
{
    //Phương thức thay đổi hoành độ của một điểm.
    //Đầu vào: hoành độ mới
    iHoanh=x;
}
void Diem::SetTungDo(float x)
{
    //Phương thức thay đổi tung độ của một điểm.
    //Đầu vào: tung độ mới
    iTung=x;
}
void Diem::TinhTien(float x,float y)
{
    //Phương thức tịnh tiến của một điểm.
    //Đầu vào: toạ độ của vector tịnh tiến
    iHoanh+=x;
    iTung+=y;
}
void Diem::PhongTo(float x)
{
    //Phương thức phóng to của một điểm.
    //Đầu vào: hệ số phóng to
    iHoanh*=x;
    iTung*=x;
}
void Diem::ThuNho(float x)
{
    //Phương thức thu nhỏ của một điểm.
    //Đầu vào: hệ số thu nhỏ
    x=1.0/x;
    iHoanh*=x;
    iTung*=x;
}
void Diem::Quay(Diem x,float y)
{
    //Phương thức quay của một điểm.
    //Đầu vào: vector quay và độ.
    iHoanh=x.iHoanh+(iHoanh-x.iHoanh)*cos(y)-(iTung-x.iTung)*sin(y);
    iTung=iTung+(iHoanh-x.iHoanh)*sin(y)+(iTung+x.iTung)*cos(y);
}