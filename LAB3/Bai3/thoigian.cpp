#include "thoigian.h"

ThoiGian::ThoiGian()
{
    iGio=0;
    iPhut=0;
    iGiay=0;
}

ThoiGian::ThoiGian(int Gio,int Phut,int Giay)
{
    iGio=Gio;
    iPhut=Phut;
    iGiay=Giay;
}

int ThoiGian::TinhGiay()
{
    return iGio*3600+iPhut*60+iGiay;
}

ThoiGian ThoiGian::TinhLaiGio(int Giay)
{
    int gio=Giay/3600;
    Giay%=3600;
    int phut=Giay/60;
    int giay=Giay%60;
    return ThoiGian(gio,phut,giay);
}

ThoiGian ThoiGian::operator +(ThoiGian a)
{
    return TinhLaiGio((TinhGiay()+a.TinhGiay())%86400);
}

ThoiGian ThoiGian::operator -(ThoiGian a)
{
    return TinhLaiGio((TinhGiay()-a.TinhGiay()+86400)%86400);
}

ThoiGian ThoiGian::operator +(int Giay)
{
    return TinhLaiGio((TinhGiay()+Giay)%86400);
}

ThoiGian ThoiGian::operator -(int Giay)
{
    return TinhLaiGio((TinhGiay()-Giay+86400)%86400);
}

ThoiGian ThoiGian::operator ++()
{
    *this=*this+1;
    return *this;
}

ThoiGian ThoiGian::operator ++(int)
{
    ThoiGian temp=*this;
    *this=*this+1;
    return temp;
}

ThoiGian ThoiGian::operator --()
{
    *this=*this-1;
    return *this;
}

ThoiGian ThoiGian::operator --(int)
{
    ThoiGian temp=*this;
    *this=*this-1;
    return temp;
}

bool ThoiGian::operator ==(ThoiGian a)
{
    return TinhGiay()==a.TinhGiay();
}

bool ThoiGian::operator !=(ThoiGian a)
{
    return !(*this==a);
}

bool ThoiGian::operator >=(ThoiGian a)
{
    return TinhGiay()>=a.TinhGiay();
}

bool ThoiGian::operator <=(ThoiGian a)
{
    return TinhGiay()<=a.TinhGiay();
}

bool ThoiGian::operator >(ThoiGian a)
{
    return TinhGiay()>a.TinhGiay();
}

bool ThoiGian::operator <(ThoiGian a)
{
    return TinhGiay()<a.TinhGiay();
}

istream& operator >>(istream& is,ThoiGian& a)
{
    is>>a.iGio>>a.iPhut>>a.iGiay;
    return is;
}

ostream& operator <<(ostream& os,ThoiGian a)
{
    os<<a.iGio<<":"<<a.iPhut<<":"<<a.iGiay;
    return os;
}
