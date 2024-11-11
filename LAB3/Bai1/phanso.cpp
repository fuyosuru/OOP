#include "phanso.h"

PhanSo::PhanSo()
{
    // Constructor mặc định: Khởi tạo phân số với tử số là 0 và mẫu số là 1
    iTu=0;
    iMau=1;
}

PhanSo::PhanSo(int Tu,int Mau=1)
{
    // Constructor: Khởi tạo phân số với tử số và mẫu số được cho (mặc định mẫu số là 1 nếu không truyền vào)
    iTu=Tu;
    iMau=Mau;
}

PhanSo::PhanSo(double x)
{
    // Constructor: Chuyển đổi số thực thành phân số bằng cách nhân với độ chính xác 5 số sau dấu phẩy rồi tối giản
    iTu=int(x*100000);
    iMau=100000;
    int g=__gcd(iTu,iMau);
    iTu/=g;
    iMau/=g;
}

PhanSo operator +(PhanSo b,PhanSo a)
{
    return PhanSo(b.iTu*a.iMau+a.iTu*b.iMau,b.iMau*a.iMau);
}

PhanSo operator -(PhanSo b,PhanSo a)
{
    return PhanSo(b.iTu*a.iMau-a.iTu*b.iMau,b.iMau*a.iMau);
}

PhanSo operator *(PhanSo b,PhanSo a)
{
    return PhanSo(b.iTu*a.iTu,b.iMau*a.iMau);
}

PhanSo operator /(PhanSo b,PhanSo a)
{
    return PhanSo(b.iTu*a.iMau,b.iMau*a.iTu);
}

bool operator ==(PhanSo b,PhanSo a)
{
    return float(a.iTu)/float(a.iMau)==float(b.iTu)/float(b.iMau);
}

bool operator !=(PhanSo b,PhanSo a)
{
    return !(b==a);
}

bool operator >=(PhanSo b,PhanSo a)
{
    return float(b.iTu)/b.iMau>=float(a.iTu)/a.iMau;
}

bool operator <=(PhanSo b,PhanSo a)
{
    return float(b.iTu)/b.iMau<=float(a.iTu)/a.iMau;
}

bool operator >(PhanSo b,PhanSo a)
{
    return float(b.iTu)/b.iMau>float(a.iTu)/a.iMau;
}

bool operator <(PhanSo b,PhanSo a)
{
    return float(b.iTu)/b.iMau<float(a.iTu)/a.iMau;
}

istream& operator >>(istream& is,PhanSo& a)
{
    is>>a.iTu>>a.iMau;
    return is;
}

ostream& operator <<(ostream& os,PhanSo a)
{
    os<<a.iTu<<"/"<<a.iMau;
    return os;
}
