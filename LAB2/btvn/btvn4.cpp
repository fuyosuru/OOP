#include<bits/stdc++.h>
using namespace std;

int m,base[1000][1000],bangnow[1000][1000],now[1000][1000];

bool xoay()
{
    //Hàm xoay ma trận theo phép biến đổi Arnold's Cat Map
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<m;++j)
        {
            int newx=(2*i+j)%m;
            int newy=(i+j)%m;
            now[newx][newy]=bangnow[i][j];
        }
    }
    for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
            bangnow[i][j]=now[i][j];
    for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
            if(bangnow[i][j]!=base[i][j])
                return false;
    return true;
}

int tim()
{
    //Hàm tìm hệ số k của phép biến đổi Arnold's Cat Map
    //Giải thích: ta sẽ xoay ma trận cho đến khi nó trở về ma trận ban đầu và đếm số lần xoay
    int k=0;
    do
    {
        k++;
    }while(!xoay());
    return k;
}

int main()
{
    cout<<"Nhap kich thuoc cua ma tran: ";
    cin>>m;
    cout<<"Nhap cac phan tu cua ma tran:\n";
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>base[i][j];
            bangnow[i][j]=base[i][j];
        }
    }
    int chuky=tim();
    cout<<"He so chu ky k la: "<<chuky<<"\n";
    return 0;
}
