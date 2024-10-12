#include<bits/stdc++.h>
using namespace std;
// Mảng để lưu trữ giá trị giai thừa từ 0 đến 20
double gt[300];
double mod(double a)
{
    // Hàm: mod
    // Đầu vào: Một số thực a.
    // Đầu ra: Trả về giá trị của a sau khi tính toán phần dư với 2π.
    // Mục đích: Đảm bảo giá trị đầu vào a nằm trong khoảng [0, 2π), 
    return a-(int(a/(2*3.14))*(2*3.14));
}

double sin(double a)
{
    // Hàm: sin
    // Đầu vào: Một số thực a (radian).
    // Đầu ra: Trả về giá trị sin của a.
    // Mục đích: Tính giá trị sin bằng cách sử dụng chuỗi Taylor với 7 số hạng đầu tiên.
    double res=a;
    double sta=-1;
    for(int i=3;i<=17;i+=2)
        {
            res=res+sta*(pow(a,i))/gt[i];
            sta=sta*-1;
        }
    return res;
}
int main()
{
    double x;
    cout<<"Nhap x: ";
    cin>>x;
    gt[0]=1; 
    for(int i=1;i<=20;i++) // Tính toán giai thừa từ 1 đến 20
        gt[i]=gt[i-1]*i;
    cout<<"Sin cua "<<x<<" rad la: "<<sin(mod(x));
}