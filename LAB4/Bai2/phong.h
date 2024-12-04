#include<bits/stdc++.h>
using namespace std;

class Phong{
protected:
    int sodem;
public:
    Phong(int sodem);
};

class Deluxe:public Phong{
private:
    double phidv,phipv;
    static int moneydeluxe;
public:
    Deluxe(int sodem,double phidv,double phipv);
    double doanhThu();
    static int getmoneydeluxe();
};

class Premium:public Phong{
private:
    double phidv;
    static int moneypremium;
public:
    Premium(int sodem,double phidv);
    double doanhThu();
    static int getmoneypremium();
};

class Business:public Phong{
private:
    static int moneybusiness;
public:
    Business(int sodem);
    double doanhThu();
    static int getmoneybusiness();
};
