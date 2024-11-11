#include "sophuc.cpp"

int main()
{
    SoPhuc a,b;
    cout<<"Nhap so phuc a: ";
    cin>>a;
    cout<<"Nhap so phuc so b: ";
    cin>>b;
    cout<<"Hai so phuc da nhap la: "<<a<<" và "<<b<<"\n";
    SoPhuc tong,hieu,thuong,tich;
    tong=a+b;
    hieu=a-b;
    thuong=a/b;
    tich=a*b;
    cout<<"a+b: "<<tong<<"\n";
    cout<<"a+2: "<<a+2<<"\n";
    cout<<"2+a: "<<2+a<<"\n";
    cout<<"a-3: "<<a-3<<"\n";
    cout<<"a==3: "<<(a==3?"True":"False")<<"\n";
    cout<<"a+2.14: "<<a+2.14<<"\n";
    cout<<"a-b: "<<hieu<<"\n";
    cout<<"a/b: "<<thuong<<"\n";
    cout<<"a*b: "<<tich<<"\n";
    cout<<"a==b: "<<(a==b?"True":"False")<<"\n";
    cout<<"a!=b: "<<(a!=b?"True":"False")<<"\n";
}
