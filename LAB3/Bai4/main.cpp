#include "date.cpp"

int main()
{
    NgayThangNam a,b;
    cout<<"Nhap ngay a: ";
    cin>>a;
    cout<<"Nhap ngay b: ";
    cin>>b;
    cout<<"Hai ngay da nhap la: "<<a<<" và "<<b<<"\n";
    cout<<"a+90(ngay): "<<a+90<<"\n";
    cout<<"a-90(ngay): "<<a-90<<"\n";
    cout<<"a-5nam-5thang-5ngay: "<<a-NgayThangNam(5,5,5)<<"\n";
    cout<<"a=b: "<<(a==b?"True":"False")<<"\n";
    cout<<"a>b: "<<(a>b?"True":"False")<<"\n";
    cout<<"a<b: "<<(a<b?"True":"False")<<"\n";
    cout<<"a>=b: "<<(a>=b?"True":"False")<<"\n";
    cout<<"a<=b: "<<(a<=b?"True":"False")<<"\n";
    cout<<"a!=b: "<<(a!=b?"True":"False")<<"\n";
    cout<<"++a: "<<++a<<"\n";
    cout<<"--a: "<<--a<<"\n";
    cout<<"a--: "<<a--<<"\n";
}
