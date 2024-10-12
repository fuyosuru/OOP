#include<bits/stdc++.h>
using namespace std;

struct PHANSO{
    long long tu; // Tử số của phân số
    long long mau; // Mẫu số của phân số
};

PHANSO taops(long long t,long long m)
{
    // Hàm: taops
    // Đầu vào: Tử số t và mẫu số m.
    // Đầu ra: Trả về một struct PHANSO với tử số và mẫu số đã truyền vào và được xử lý.
    // Mục đích: Tạo một phân số. Nếu mẫu số là 0, nó sẽ được thay thế bằng 1 và in thông báo đã thay đổi.
    // Nếu mẫu số âm, cả tử số và mẫu số sẽ được nhân với -1 để đảm bảo mẫu số dương.
    PHANSO ps;
    ps.tu=t;
    if(m==0)
    {
        cout<<"Mau so khong the bang 0. Doi mau = 1."<<"\n";
        ps.mau=1;
    }
    else
    {
        ps.mau=m;
    }
    if(ps.mau<0)
    {
        ps.mau*=-1;
        ps.tu*=-1;
    }
    long long g=__gcd(ps.tu,ps.mau);
    ps.tu/=g;
    ps.mau/=g;
    return ps;
}

PHANSO cong(PHANSO ps1,PHANSO ps2)
{
    // Hàm: cong
    // Đầu vào: Hai struct PHANSO ps1 và ps2.
    // Đầu ra: Trả về tổng của hai phân số dưới dạng một struct PHANSO.
    // Mục đích: Tính tổng hai phân số.
    return taops(ps1.tu*ps2.mau+ps2.tu*ps1.mau,ps1.mau*ps2.mau);
}

PHANSO tru(PHANSO ps1,PHANSO ps2)
{
    // Hàm: tru
    // Đầu vào: Hai struct PHANSO ps1 và ps2.
    // Đầu ra: Trả về hiệu của hai phân số dưới dạng một struct PHANSO.
    // Mục đích: Tính hiệu hai phân số.
    return taops(ps1.tu*ps2.mau-ps2.tu*ps1.mau,ps1.mau*ps2.mau);
}

PHANSO nhan(PHANSO ps1,PHANSO ps2)
{
    // Hàm: nhan
    // Đầu vào: Hai struct PHANSO ps1 và ps2.
    // Đầu ra: Trả về tích của hai phân số dưới dạng một struct PHANSO.
    // Mục đích: Tính tích hai phân số.
    return taops(ps1.tu*ps2.tu,ps1.mau*ps2.mau);
}

PHANSO chia(PHANSO ps1,PHANSO ps2)
{
    // Hàm: chia
    // Đầu vào: Hai struct PHANSO ps1 và ps2.
    // Đầu ra: Trả về thương của hai phân số dưới dạng một struct PHANSO.
    // Mục đích: Tính thương hai phân số.
    return taops(ps1.tu*ps2.mau,ps1.mau*ps2.tu);
}

void xuatPhanSo(PHANSO ps)
{
    // Hàm: xuatphanso
    // Đầu vào: Một struct PHANSO ps.
    // Mục đích: Xuất phân số.
    printf("%lld/%lld\n",ps.tu,ps.mau);
}

int main()
{
    cout<<"Nhap tu cua phan so thu nhat: ";
    long long x;
    cin>>x;
    cout<<"Nhap mau cua phan so thu nhat: ";
    long long y;
    cin>>y;
    PHANSO ps1=taops(x,y);
    cout<<"Nhap tu cua phan so thu hai: ";
    cin>>x;
    cout<<"Nhap mau cua phan so thu hai: ";
    cin>>y;
    PHANSO ps2=taops(x,y);
    cout<<"Tong 2 phan so la: ";
    xuatPhanSo(cong(ps1,ps2));
    cout<<"Hieu 2 phan so la: ";
    xuatPhanSo(tru(ps1,ps2));
    cout<<"Tich 2 phan so la: ";
    xuatPhanSo(nhan(ps1,ps2));
    cout<<"Thuong 2 phan so la: ";
    xuatPhanSo(chia(ps1,ps2));
}
