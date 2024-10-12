#include <bits/stdc++.h>
using namespace std;

int A[100];   
int B[1000];  
int pos[100]; 
int n,m;
int Tim() 
{
    int c=0;
    for (int i=1;i<=m-n+1;i++) 
    {
        bool ok=true;
        for (int j=1;j<=n; j++) 
        {
            if (B[i+j-1] != A[j]) 
            {
                ok=false;
                break;
            }
        }
        if (ok) 
            pos[++c] = i;
    }

    return c;
}

int main() 
{

    cout<<"Nhap so phan tu cua mang A: ";
    cin>>n;
    cout<<"Nhap mang co "<<n<<" phan tu: ";
    for(int i=1;i<=n;i++)
        cin>>A[i];
    cout<<"Nhap so phan tu cua mang B: ";
    cin>>m;
    cout<<"Nhap mang co "<<m<<" phan tu: ";
    for(int i=1;i<=m;i++)
        cin>>B[i];
    int res=Tim();
    cout<<"So lan mang A xuat hien trong mang B la: "<<res<<"\n";
    cout<<"Cac vi tri mang A xuat hien trong mang B la: ";
    for(int i=1;i<=res;i++)
        cout<<pos[i]<<" ";
    return 0;
}
