#include "thoigian.cpp"

int main()
{
    ThoiGian a,b;
    cout<<"nhap thoi gian thu nhat: ";
    cin>>a;
    cout<<"nhap thoi gian thu hai: ";
    cin>>b;
    cout<<"Hai thoi gian da nhap la: "<<a<<" và "<<b<<"\n";
    cout<<"TinhLaiGio(3000): "<<a.TinhLaiGio(3000)<<"\n";
    cout<<"TinhGiay(a)="<<a.TinhGiay()<<"\n";
    cout<<"a+b: "<<a+b<<"\n";
    cout<<"a-b: "<<a-b<<"\n";
    cout<<"a+90 giay : "<<a+90<<"\n";
    cout<<"b-120 giay: "<<b-120<<"\n";
    cout<<"++a: "<<++a<<"\n";
    cout<<"a++: "<<a++<<"\n";
    cout<<"--b: "<<--b<<"\n";
    cout<<"b--: "<<b--<<"\n";
    cout<<"a==b: "<<(a==b?"True":"False")<<"\n";
    cout<<"a!=b: "<<(a!=b?"True":"False")<<"\n";
    cout<<"a>b: "<<(a>b?"True":"False")<<"\n";
    cout<<"a<b: "<<(a<b?"True":"False")<<"\n";

    return 0;
}
