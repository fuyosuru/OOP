#include "NhanVien.cpp"
int main() 
{
    string ms_ql, ten_ql;
    double luongcb_ql, tyLeThuong;
    cout<<"Nhap thong tin quan ly: \n";
    cout<<"Ma so: "; 
    cin>>ms_ql;
    cout<<"Ten: "; 
    cin.ignore(); 
    getline(cin, ten_ql);
    cout<<"Luong co ban: "; 
    cin>>luongcb_ql;
    cout<<"Ty le thuong: "; 
    cin>>tyLeThuong;
    QuanLy quanLy(ms_ql, ten_ql, luongcb_ql, tyLeThuong);
    string ms_ks, ten_ks;
    double luongcb_ks;
    int giolamthem;
    cout<<"\nNhap thong tin ky su: \n";
    cout<<"Ma so: "; 
    cin>>ms_ks;
    cout<<"Ten: "; 
    cin.ignore(); 
    getline(cin, ten_ks);
    cout<<"Luong co ban: "; 
    cin>>luongcb_ks;
    cout<<"So gio lam them: "; 
    cin>>giolamthem;
    KySu kySu(ms_ks, ten_ks, luongcb_ks, giolamthem);
    cout<<"\nThong tin quan ly: \n";
    quanLy.Xuat();
    cout<<"\nThong tin ky su: \n";
    kySu.Xuat();
}
