#include<bits/stdc++.h>
using namespace std;

struct PHANSO{
    //struct lưu thông tin của một phân số.
    int tu,mau;
};

PHANSO nhan(PHANSO a,PHANSO b)
{
    //Hàm nhân 2 phân số.
    //Đầu vào: 2 phân số a và b.
    //Đầu ra: tích của 2 phân số a và b.
    PHANSO c;
    c.tu=a.tu*b.tu;
    c.mau=a.mau*b.mau;
    return c;
}

int n;
PHANSO ps[100],subset[100],k;

bool bang(PHANSO a,PHANSO b)
{
    //Hàm so sánh 2 phân số.
    //Đầu vào: 2 phân số a và b.
    //Đầu ra: true nếu a=b, false cho trường hợp còn lại
    return a.tu*b.mau==b.tu*a.mau;
}

bool sosanh(PHANSO a,PHANSO b)
{
    //Hàm so sánh 2 phân số.
    //Đầu vào: 2 phân số a và b.
    //Đầu ra: true nếu a<b, false cho trường hợp còn lại
    return a.tu*b.mau<b.tu*a.mau;
}

void tim()
{
    //Hàm tìm các tập con của một mảng phân số sao cho tích các phần tử trong tập con bằng một phân số k cho trước.
    /*Giải thích: ta xét tất cả các tập con có thể có bằng cách sinh các ra các bitwise mask có dạng n bit, với những bit là 1 có nghĩa là 
    số tại vị trí đó nằm trong tập con, ngược lại cho bit 0, ta sét tích của từng tập con và so sánh với phân số k.*/
    int allmask=1<<n; 
    int size=0,best=0;
    for(int mask=1;mask<allmask;++mask)
    {
        PHANSO res={1,1};
        int now=0;
        PHANSO setps[100];
        for(int i=0;i<n;++i)
        {
            if(mask&(1<<i))
            {
                res=nhan(res,ps[i+1]);
                setps[now++]=ps[i+1];
            }
        }
        if(bang(res,k))
        {
            if(best==0 || now<best)
            {
                for(int i=0;i<now;++i)
                    subset[i]=setps[i];
                best=now;
            }
        }
    }
    if(best==0)
        cout<<"Khong co tap hop nao phu hop!";
    else
    {
        cout<<"Tap con thoa dieu kien la: ";
        for(int i=0;i<best;i++)
            cout<<subset[i].tu<<"/"<<subset[i].mau<<" ";

    }
}

int main()
{
    
    cout<<"Nhap so luong phan so: ";
    cin>>n;
    
    for(int i=1;i<=n;++i)
    {
        cout<<"Nhap tu va mau cua phan so thu "<<i<<": ";
        cin>>ps[i].tu>>ps[i].mau;
        while(ps[i].mau==0)
        {
            cout<<"Mau khong the bang khong! Nhap lai mau so: ";
            cin>>ps[i].mau;
        }
    }
    cout<<"Nhap tu va mau cua phan so dich: ";
    cin>>k.tu>>k.mau;
    tim();
    return 0;
}
