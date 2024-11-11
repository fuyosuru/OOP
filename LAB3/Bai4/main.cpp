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
    cout<<"a-3nam-2thang-1ngay: "<<a-NgayThangNam(3,2,1)<<"\n";
    cout<<"++a: "<<++a<<"\n";
    cout<<"--a: "<<--a<<"\n";
    cout<<"a=b: "<<(a==b)<<"\n";
    cout<<"a>b: "<<(a>b)<<"\n";
    cout<<"a<b: "<<(a<b)<<"\n";
    cout<<"a>=b: "<<(a>=b)<<"\n";
    cout<<"a<=b: "<<(a<=b)<<"\n";
    cout<<"a!=b: "<<(a!=b)<<"\n";
}