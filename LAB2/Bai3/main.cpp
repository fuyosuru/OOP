#include "dagiac.cpp"

int main()
{
    DaGiac tg;
    tg.Nhap();
    tg.Xuat();
    DaGiac x=tg;
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