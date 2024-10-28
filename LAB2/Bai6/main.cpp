#include "tamgiac.cpp"

int main()
{
    TamGiac tg;
    tg.Nhap();
    std::cout<<"nhap huong tinh tien: ";
    float h,k;
    std::cin>>h;
    std::cout<<"Nhap do dai tinh tien: ";
    std::cin>>k;
    tg.TinhTien(3.14*(h/180),k);
    std::cout<<"Toa 3 diem cua tam giac sau khi tinh tien la:\n";
    tg.Xuat();
}