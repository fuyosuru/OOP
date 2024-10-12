#include<bits/stdc++.h>
using namespace std;
// Mảng Count lưu trữ số ngày tích lũy trong năm cho cả năm thường (0) và năm nhuận (1)
int Count[2][14] = {
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},    // Ngày trong năm thường
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}     // Ngày trong năm nhuận
};
struct DATE{
    int ngay;
    int thang;
    bool nhuan;
    int encode; //số đã mã hoá của ngày và tháng
    int nam;
    
};

void xuat(DATE ngay)
{
        // Hàm để xuất ngày theo định dạng dd/mm/yyyy
        // Đầu vào: Một đối struct DATE
        // Mục đích: Xuất ngày ra màn hình
        printf("%d/%d/%d\n",ngay.ngay,ngay.thang,ngay.nam);
}

DATE taongay(int ng, int th,int na)
{
        // Hàm tạo struct DATE từ ngày, tháng, năm
        // Đầu vào: ng - ngày, th - tháng, na - năm
        // Đầu ra: Đối tượng DATE với các thông tin ứng với ngày, tháng, năm đã nhập
        DATE ngay;
        ngay.ngay=ng;
        ngay.thang=th;
        ngay.nam=na;
        ngay.nhuan=0;
        if(ngay.nam > 1000 && ngay.nam%4==0 && ngay.nam%100!=0)
            ngay.nhuan=1;
        ngay.encode=Count[ngay.nhuan][th]+ngay.ngay;
        return ngay;
}

DATE taongayen(int en,int na)
{
        // Hàm tạo struct DATE từ encode và năm
        // Đầu vào: en - encode, na - năm
        // Đầu ra: Đối struct DATE ứng với encode và năm đã nhập
        DATE ngay;
        ngay.nhuan=0;
        ngay.encode=en;
        ngay.nam=na;
        if(na > 1000 && na%4==0 && na%100!=0)
            ngay.nhuan=1;
        if(en>Count[ngay.nhuan][13])
        {
            ngay.nam=na+1;
            ngay.nhuan=0;
            if(ngay.nam > 1000 && ngay.nam%4==0 && ngay.nam%100!=0)
                ngay.nhuan=1;
            ngay.encode=1;
        }
        if(en==0)
        {
            ngay.nam=na-1;
            ngay.nhuan=0;
            if(ngay.nam > 1000 && ngay.nam%4==0 && ngay.nam%100!=0)
                ngay.nhuan=1;
            ngay.encode=Count[ngay.nhuan][13];
        }
        for(int i=2 ; i<=13 ;i++)
            if(Count[ngay.nhuan][i]>=ngay.encode)
            {
                ngay.thang=i-1;
                ngay.ngay=ngay.encode-Count[ngay.nhuan][i-1];
                break;
            }
        return ngay;
}

int main()
{
    cout<<"Nhap ngay/thang/nam: ";
    int x,y,z;
    cin>>x>>y>>z;
    DATE da;
    da=taongay(x,y,z);
    cout<<"Ngay da nhap la ngay: ";
    xuat(da);
     // Tạo struct DATE ứng với ngày tiếp theo và ngày trước đó
    DATE ngaymai=taongayen(da.encode+1,da.nam);
    DATE homqua=taongayen(da.encode-1,da.nam);
    cout<<"Ngay ke tiep la ngay: ";
    xuat(ngaymai);
    cout<<"Ngay truoc do la ngay: ";
    xuat(homqua);
    cout<<"day la ngay thu "<<da.encode<<" trong nam\n";
}