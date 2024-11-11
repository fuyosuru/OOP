#include "sophuc.h"

SoPhuc::SoPhuc()
{
    dThuc=0;
    dAo=0;
}

SoPhuc::SoPhuc(double thuc,double ao=0)
{
    dThuc=thuc;
    dAo=ao;
}

SoPhuc operator +(SoPhuc b,SoPhuc a)
{
    return SoPhuc(b.dThuc+a.dThuc,b.dAo+a.dAo);
}

SoPhuc operator -(SoPhuc b,SoPhuc a)
{
    return SoPhuc(b.dThuc-a.dThuc,b.dAo-a.dAo);
}

SoPhuc operator *(SoPhuc b,SoPhuc a)
{
    return SoPhuc(b.dThuc*a.dThuc-b.dAo*a.dAo,b.dThuc*a.dAo+b.dAo*a.dThuc);
}

SoPhuc operator /(SoPhuc b,SoPhuc a)
{
    double d=a.dThuc*a.dThuc+a.dAo*a.dAo;
    return SoPhuc((b.dThuc*a.dThuc+b.dAo*a.dAo)/d,(b.dAo*a.dThuc-b.dThuc*a.dAo)/d);
}

bool operator ==(SoPhuc b,SoPhuc a)
{
    return b.dThuc==a.dThuc && b.dAo==a.dAo;
}

bool operator !=(SoPhuc b,SoPhuc a)
{
    return !(b==a);
}

istream& operator >>(istream& is,SoPhuc& a)
{
    is>>a.dThuc>>a.dAo;
    return is;
}

ostream& operator <<(ostream& os,SoPhuc a)
{
    os<<a.dThuc<<(a.dAo>=0?"+":"")<<a.dAo<<"i";
    return os;
}
