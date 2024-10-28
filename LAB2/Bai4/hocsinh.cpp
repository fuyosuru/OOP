#include "hocsinh.h"

ThiSinh::ThiSinh() : iNgay(0), iThang(0), iNam(0), fToan(0.0), fVan(0.0), fAnh(0.0) {}

void ThiSinh::Nhap() 
{
    //Phương thức nhập thông tin của sinh viên.
    std::cin.ignore();
    std::cout<<"Nhap ten: "; 
    getline(std::cin, Ten);
    std::cout<<"Nhap MSSV: "; 
    getline(std::cin, MSSV);
    std::cout<<"Nhap ngay sinh: "; 
    std::cin>>iNgay;
    std::cout<<"Nhap thang sinh: "; 
    std::cin>>iThang;
    std::cout<<"Nhap nam sinh: "; 
    std::cin>>iNam;
    std::cout<<"Nhap diem Toan: "; 
    std::cin>>fToan;
    std::cout<<"Nhap diem Van: "; 
    std::cin>>fVan;
    std::cout<<"Nhap diem Anh: "; 
    std::cin>>fAnh;
}

void ThiSinh::Xuat()
{
    //Phương thức xuất thông tin của sinh viên.
    std::cout<<"Ten: "<<Ten<<"\n";
    std::cout<<"MSSV: "<<MSSV<<"\n";
    std::cout<<"Ngay sinh: "<<iNgay<<"/"<<iThang<<"/"<<iNam<<"\n";
    std::cout<<"Diem Toan: "<<fToan<<"\n";
    std::cout<<"Diem Van: "<<fVan<<"\n";
    std::cout<<"Diem Anh: "<<fAnh<<"\n";
}

float ThiSinh::Tong() 
{
    //Phương thức tính tổng điểm của sinh viên.
    //Đầu ra: tổng điểm của sinh viên.
    return fToan + fVan + fAnh;
}