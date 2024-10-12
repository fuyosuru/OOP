#include<bits/stdc++.h>
using namespace std;

struct PHANSO {
    long long tu; // Tử số của phân số
    long long mau; // Mẫu số của phân số
};
PHANSO rutgon(PHANSO &x)
{
        // Hàm: rutgon
        // Đầu vào: Tham chiếu đến một struct PHANSO x.
        // Đầu ra: Trả về một struct PHANSO với tử số và mẫu số của x đã được rút gọn.
        // Mục đích: Hàm này rút gọn phân số bằng cách chia tử số và mẫu số cho ước chung lớn nhất (GCD).
        // Nếu mẫu số bằng 0, nó sẽ được đặt thành 1. Nếu mẫu số âm, cả tử số và mẫu số sẽ được nhân với -1
        // để đảm bảo phân số có mẫu số dương.
        if (x.mau==0) 
        {
            cout<<"Mau so khong the bang 0. Doi mau = 1."<<"\n";
            x.mau=1;
        }
        long long g=__gcd(x.tu,x.mau);
        x.tu=x.tu/g;
        x.mau=x.mau/g;
        if (x.mau<0)
            {
                x.mau=x.mau*-1;
                x.tu=x.tu*-1;
            }
        return x;
}

int main() 
{
    cout<<"Nhap tu cua phan so: ";
    long long x;
    cin>>x;
    cout<<"Nhap mau cua phan so: ";
    long long y;
    cin>>y;
    PHANSO ps;
    ps.tu=x;
    ps.mau=y;
    ps=rutgon(ps);
    printf("Phan so sau khi rut gon la: %lld/%lld",ps.tu,ps.mau);
    
}
