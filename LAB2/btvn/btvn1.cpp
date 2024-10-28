#include <bits/stdc++.h>
using namespace std;

struct PHANSO{
    //struct lưu thông tin của một phân số.
    int tu,mau;
};

int main()
{
    int n;
    cout<<"Nhap so luong phan so: ";
    cin>>n;
    PHANSO ps[10000];
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
    PHANSO psmin=ps[1],psmax=ps[1];
    for(int i=2;i<=n;++i)
    {
        if(ps[i].tu*psmin.mau<psmin.tu*ps[i].mau)
            psmin=ps[i];
        if(ps[i].tu*psmax.mau>psmax.tu*ps[i].mau)
            psmax=ps[i];
    }
    cout<<"Phan so nho nhat la: "<<psmin.tu<<"/"<<psmin.mau<<"\n";
    cout<<"Phan so lon nhat la: "<<psmax.tu<<"/"<<psmax.mau<<"\n";
    return 0;
}
