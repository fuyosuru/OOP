#include "date.h"
int doingay(int thang,int nam)
{
    int Ngay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(thang==2 && ((nam%4==0 && nam%100!=0) || nam%400==0))
        return 29; 
    return Ngay[thang-1];
}

NgayThangNam::NgayThangNam()
{
    iNgay=1;
    iThang=1;
    iNam=2000;
}

NgayThangNam::NgayThangNam(int Ngay,int Thang,int Nam)
{
    iNam=Nam;
    iThang=Thang;
    iNgay=Ngay;
}

NgayThangNam NgayThangNam::operator +(int Ngay)
{
    NgayThangNam result=*this;
    result.iNgay+=Ngay;
    while(result.iNgay>doingay(result.iThang,result.iNam))
    {
        result.iNgay-=doingay(result.iThang,result.iNam);
        result.iThang++;
        if(result.iThang>12)
        {
            result.iThang=1;
            result.iNam++;
        }
    }
    return result;
}

NgayThangNam NgayThangNam::operator -(int Ngay)
{
    NgayThangNam result=*this;
    result.iNgay-=Ngay;
    while(result.iNgay<=0)
    {
        result.iThang--;
        if(result.iThang<=0)
        {
            result.iThang=12;
            result.iNam--;
        }
        result.iNgay+=doingay(result.iThang,result.iNam);
    }
    return result;
}

NgayThangNam NgayThangNam::operator -(NgayThangNam a)
{
    NgayThangNam result=*this;
    result.iNgay-=a.iNgay;
    result.iNam-=a.iNam;
    result.iThang-=a.iThang;
    while(result.iThang<=0)
    {
        result.iNam--;
        result.iThang+=12;
    }
    while(result.iNgay<=0)
    {
        result.iThang--;
        if(result.iThang<=0)
        {
            result.iThang=12;
            result.iNam--;
        }
        result.iNgay+=doingay(result.iThang,result.iNam);
    }
    return result;
}

NgayThangNam NgayThangNam::operator ++()
{
    *this=*this+1;
    return *this;
}

NgayThangNam NgayThangNam::operator ++(int)
{
    NgayThangNam temp=*this;
    *this=*this+1;
    return temp;
}

NgayThangNam NgayThangNam::operator --()
{
    *this=*this-1;
    return *this;
}

NgayThangNam NgayThangNam::operator --(int)
{
    NgayThangNam temp=*this;
    *this=*this-1;
    return temp;
}

int NgayThangNam::TinhNgay()
{
    int res=0;
    for(int i=1;i<iThang;i++)
        res+=doingay(i,iNam);
    res+=iNgay;
    return res;
}

bool NgayThangNam::operator ==(NgayThangNam b)
{
    return iNgay==b.iNgay && iThang==b.iThang && iNam==b.iNam;
}

bool NgayThangNam::operator !=(NgayThangNam b)
{
    return !(*this==b);
}

bool NgayThangNam::operator >=(NgayThangNam b)
{
    return iNam>b.iNam || (iNam==b.iNam && (iThang>b.iThang || (iThang==b.iThang && iNgay>=b.iNgay)));
}

bool NgayThangNam::operator <=(NgayThangNam b)
{
    return iNam<b.iNam || (iNam==b.iNam && (iThang<b.iThang || (iThang==b.iThang && iNgay<=b.iNgay)));
}

bool NgayThangNam::operator >(NgayThangNam b)
{
    return !(*this<=b);
}

bool NgayThangNam::operator <(NgayThangNam b)
{
    return !(*this>=b);
}

istream& operator >>(istream& is,NgayThangNam& a)
{
    is>>a.iNgay>>a.iThang>>a.iNam;
    return is;
}

ostream& operator <<(ostream& os,NgayThangNam a)
{
    os<<a.iNgay<<"/"<<a.iThang<<"/"<<a.iNam;
    return os;
}