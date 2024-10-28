#include<bits/stdc++.h>
using namespace std;

struct PHANSO{
    //struct lưu thông tin của một phân số.
    int tu,mau;
};

bool sosanh(PHANSO a,PHANSO b)
{
    //Hàm so sánh 2 phân số.
    //Đầu vào: 2 phân số a và b.
    //Đầu ra: true nếu a<b, false cho trường hợp còn lại
    return a.tu*b.mau<b.tu*a.mau;
}
int main()
{
    int n,k;
    PHANSO ps[10000];
    cout<<"Nhap so luong phan so va k: ";
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cout<<"nhap tu va mau cua phan so thu "<<i<<": ";
        cin>>ps[i].tu>>ps[i].mau;
        while(ps[i].mau==0)
        {
            cout<<"Mau khong the bang khong!. Nhap lai mau so: ";
            cin>>ps[i].mau;
        }
    }
    sort(ps+1,ps+n+1,sosanh);
    if(k<=n)
        {
            cout<<"Phan so be thu k la: "<<ps[k].tu<<"/"<<ps[k].mau<<"\n";
            cout<<"Phan so lon thu k la: "<<ps[n-k+1].tu<<"/"<<ps[n-k+1].mau<<"\n";
        }
    return 0;
}
