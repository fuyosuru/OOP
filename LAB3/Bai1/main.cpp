#include "phanso.cpp"

int main()
{
    PhanSo a,b;
    cout<<"Nhap phan so a: ";
    cin>>a;
    cout<<"Nhap phan so b: ";
    cin>>b;
    cout<<"Hai phan so da nhap: "<<a<<" và "<<b<<"\n";
    PhanSo tong,hieu,thuong,tich;
    tong=a+b;
    hieu=a-b;
    thuong=a/b;
    tich=a*b;
    cout<<"a+b: "<<tong<<"\n";
    cout<<"a+2: "<<a+2<<"\n";
    cout<<"a+2.5: "<<a+2.5<<"\n";
    cout<<"a-b: "<<hieu<<"\n";
    cout<<"a/b: "<<thuong<<"\n";
    cout<<"a*b: "<<tich<<"\n";
    cout<<"a<b: "<<(a<b?"True":"False")<<"\n";
    cout<<"a>b: "<<(a>b?"True":"False")<<"\n";
    cout<<"a<=b: "<<(a<=b?"True":"False")<<"\n";
    cout<<"a>=b: "<<(a>=b?"True":"False")<<"\n";
    cout<<"a==b: "<<(a==b?"True":"False")<<"\n";
    cout<<"a!=b: "<<(a!=b?"True":"False")<<"\n";
}
