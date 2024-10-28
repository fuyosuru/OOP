#include "dagiac.cpp"

int main()
{
    DaGiac dg;
    dg.Nhap();
    dg.SapXep();
    std::cout<<"Dien tich cua da giac la: "<<dg.TinhDienTich()<<"\n";
    return 0;
}