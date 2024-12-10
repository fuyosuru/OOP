#include <bits/stdc++.h>
using namespace std;

class cNgay {
private:
    int ngay, thang, nam;

public:
    cNgay(): ngay(1), thang(1), nam(1) {}

    cNgay(int _nam, int _thang, int _ngay=1): ngay(_ngay), thang(_thang), nam(_nam) {}

    friend istream& operator>>(istream& is, cNgay& ng) 
    {
        cout<<"Nhap mot ngay: ";
        is>>ng.ngay>>ng.thang>>ng.nam;
        return is;
    }

    friend ostream& operator<<(ostream& os, cNgay ng) 
    {
        cout<<"Ngay da nhap la: ";
        os<<ng.ngay<<"/"<<ng.thang<<"/"<< ng.nam<<"\n";
        return os;
    }

    bool operator<(cNgay var)  
    {
        if (nam<var.nam) 
            return true;
        if (nam>var.nam) 
            return false;
        if (thang<var.thang) 
            return true;
        if (thang>var.thang) 
            return false;
        return ngay<var.ngay;
    }
};

int main() 
{
    cNgay ng1;
    cNgay ng2(2017, 1);
    cNgay ng3(2017, 1, 7); 
    cin>>ng1;
    cout<<ng1;
    if (ng1<ng2)
        cout<<"Ngay 1 truoc ngay 2"<<endl;
    else
        cout<<"Ngay 1 khong truoc ngay 2"<<endl;
}
