#include "tamgiac.cpp"

int main()
{
    TamGiac tg;
    tg.Nhap();
    std::cout<<"Tam giac da nhap: \n";
    tg.Xuat();
    TamGiac x=tg;
    x.TinhTien(3,4);
    std::cout<<"Sau khi tinh tien: \n";
    x.Xuat();
    x=tg;
    x.PhongTo(4);
    std::cout<<"Sau khi phong to: \n";
    x.Xuat();
    x=tg;
    x.ThuNho(4);
    std::cout<<"Sau khi thu nho: \n";
    x.Xuat();
    x=tg;
    x.Quay(Diem(2,3),30);
    std::cout<<"Sau khi quay: \n";
    x.Xuat();
}