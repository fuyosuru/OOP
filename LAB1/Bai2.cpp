#include<bits/stdc++.h>
using namespace std;

struct PHANSO{
    long long tu; // Tử số của phân số
    long long mau; // Mẫu số của phân số
};

PHANSO taops(long long t, long long m) 
{
    // Hàm: taops
    // Đầu vào: Tử số t và mẫu số m.
    // Đầu ra: Trả về một struct PHANSO với tử số và mẫu số đã truyền vào và được xử lý.
    // Mục đích: Tạo một phân số. Nếu mẫu số là 0, nó sẽ được thay thế bằng 1 và in thông báo đã thay đổi.
    // Nếu mẫu số âm, cả tử số và mẫu số sẽ được nhân với -1 để đảm bảo mẫu số dương.   
    PHANSO ps;
    ps.tu=t;
    ps.mau=m;
    if(m==0)
        ps.mau=1;
    if (m == 0) 
        cout << "Mau so khong the bang 0. Doi mau = 1." << "\n";
    if (ps.mau<0) 
    {
        ps.mau*=-1;
        ps.tu*=-1;
    }
    return ps;
}

int tru(PHANSO ps1, PHANSO ps2)
{
    // Hàm: tru
    // Đầu vào: Hai struct PHANSO ps1 và ps2.
    // Đầu ra: Trả về tử số của hiệu của hai phân số.
    // Mục đích: Tính tử số của hiệu của hai phân số.
    int res;
    res=ps1.tu*ps2.mau-ps2.tu*ps1.mau;
    return res;
}

void xuatphanso(PHANSO ps)
{
    // Hàm: xuatphanso
    // Đầu vào: Một struct PHANSO ps.
    // Mục đích: Xuất phân số.
    printf("%lld/%lld\n", ps.tu, ps.mau);
}

int main() 
{
    cout<<"Nhap tu cua phan so thu nhat: ";
    long long x;
    cin>>x;
    cout<<"Nhap mau cua phan so thu nhat: ";
    long long y;
    cin>>y;
    PHANSO ps1=taops(x, y);
    cout<<"Nhap tu cua phan so thu hai: ";
    cin>>x;
    cout<<"Nhap mau cua phan so thu hai: ";
    cin>>y;
    PHANSO ps2 = taops(x, y);
    int hieu = tru(ps1, ps2);
    if(hieu<0) 
    {
        cout<<"Phan so lon hon la: ";
        xuatphanso(ps2);
    }
    else 
        {
            cout<<"Phan so lon hon la: ";
            xuatphanso(ps1);
        }
    return 0;
}
