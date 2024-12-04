#include "giasuc.h"

GiaSuc::GiaSuc(int soluong):sl(soluong){}
Bo::Bo(int soluong):GiaSuc(soluong){}
Cuu::Cuu(int soluong):GiaSuc(soluong){}
De::De(int soluong):GiaSuc(soluong){}
int GiaSuc::sosua=0;

int GiaSuc::getsl()
{
    return sl;
}

int GiaSuc::getsosua()
{
    return sosua;
}

string Bo::keu()
{
    return "Moo Moo!\n";
}
void Bo::chosua()
{
    for(int i=0;i<sl;i++)
        sosua+=rand()%21;
}
void Bo::sinhcon()
{
    int res=0;
    for(int i=0;i<sl;i++)
        res+=rand()%3;
    sl+=res;
}

string Cuu::keu()
{
    return "Bee Bee!\n";
}
void Cuu::chosua()
{
    for(int i=0;i<sl;i++)
        sosua+=rand()%6;
}
void Cuu::sinhcon()
{
    int res=0;
    for(int i=0;i<sl;i++)
        res+=rand()%3;
    sl+=res;
}
string De::keu()
{
    return "Maa Maa!\n";
}
void De::chosua()
{
    for(int i=0;i<sl;i++)
        sosua+=rand()%11;
}
void De::sinhcon()
{
    int res=0;
    for(int i=0;i<sl;i++)
        res+=rand()%3;
    sl+=res;
}
