#include"Phong.h"

int Deluxe::moneydeluxe=0;
int Premium::moneypremium=0;
int Business::moneybusiness=0;
Phong::Phong(int sodem):sodem(sodem){}
Deluxe::Deluxe(int sodem,double phidv,double phipv):Phong(sodem),phidv(phidv),phipv(phipv)
{
    moneydeluxe+=sodem*750000+phidv+phipv;
}
double Deluxe::doanhThu()
{
    return sodem*750000+phidv+phipv;
}
int Deluxe::getmoneydeluxe()
{
    return moneydeluxe;
}
Premium::Premium(int sodem,double phidv):Phong(sodem),phidv(phidv)
{
    moneypremium+=sodem*500000+phidv;
}
double Premium::doanhThu()
{
    return sodem*500000+phidv;
}
int Premium::getmoneypremium()
{
    return moneypremium;
}
Business::Business(int sodem):Phong(sodem)
{
    moneybusiness+=sodem*300000;
}
double Business::doanhThu()
{
    return sodem*300000;
}
int Business::getmoneybusiness()
{
    return moneybusiness;
}
