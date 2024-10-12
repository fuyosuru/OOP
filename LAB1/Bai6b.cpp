#include <bits/stdc++.h>
using namespace std;

struct HOCSINH
{
    string hoTen,xepLoai;
    float diemToan, diemVan, diemAnh, diemTB;
};

HOCSINH HS[100];  
int n;           

string lowercase(string s)
{
    // Hàm chuyển chuỗi thành chữ thường
    // Đầu vào: Chuỗi ký tự s
    // Đầu ra: Chuỗi ký tự sau khi đã chuyển toàn bộ thành chữ thường
    for (int i=0; i<s.size();i++) 
        s[i]=tolower(s[i]);
    return s;
}

bool checkten(string hoTen)
{
    // Hàm kiểm tra tên có hợp lệ hay không
    // Đầu vào: Chuỗi ký tự hoTen (tên của học sinh)
    // Đầu ra: Trả về true nếu tên hợp lệ, ngược lại là false
    // Mục đích: kiểm tra ên hợp lệ hay không
    if (hoTen.size()==0) 
        {
            cout<<"Ho ten khong hop le. Vui long nhap lai.\n";
            return false;
        }
    for (int i=0; i<hoTen.size(); i++)
    {
        if (isdigit(hoTen[i])) 
            {
                cout<<"Ho ten khong hop le. Vui long nhap lai.\n";
                return false;
            }
    }
    return true;
}

float nhap()
{
    // Hàm nhập điểm cho học sinh, đảm bảo điểm trong khoảng 0 đến 10
    // Output: Trả về điểm hợp lệ (float) đã được nhập vào
    float diem;
    while (true)
    {
        cin>>diem;
        if (diem>=0 && diem<=10) 
            break;
        cout<<"Diem phai trong khoang tu 0 den 10.\nNhap lai: ";
    }
    return diem;
}

void xeploaihs(HOCSINH &hs)
{
    // Hàm xếp loại học sinh dựa trên điểm trung bình
    // Đầu vào: HOCSINH hs
    // Mục đích: xếp loại đối tượng học sinh theo điểm trung bình
    if (hs.diemTB>=9) 
        hs.xepLoai = "Xuat sac";
    else 
        if (hs.diemTB >= 8) 
            hs.xepLoai = "Gioi";
        else 
            if (hs.diemTB >= 6.5) 
                hs.xepLoai = "Kha";
            else 
                if (hs.diemTB >= 5) 
                    hs.xepLoai = "Trung binh";
                else 
                    hs.xepLoai = "Yeu";
}

void Diemtb(HOCSINH &hs)
{
    // Hàm tính điểm trung bình cho học sinh
    // Đầu vào: Tham chiếu đến đối tượng học sinh hs
    // Mục đích: Tính điểm trung bình cho hs
    hs.diemTB=(2*hs.diemToan+hs.diemVan+hs.diemAnh)/4;
}

void Timten(string keyword)
{
    // Hàm tìm kiếm học sinh theo từ khóa tên
    // Đầu vào: Chuỗi keyword (từ khóa tìm kiếm)
    // Mục đích: In ra danh sách học sinh có tên chứa từ khóa (không phân biệt hoa thường)
    bool ok=false;
    string keywordLower=lowercase(keyword);
    for (int i=1; i<=n; i++)
    {
        string hoTenLower=lowercase(HS[i].hoTen);
        if (hoTenLower.find(keywordLower) != string::npos)  
        {
            ok=true;
            cout<<"Ho ten: " << HS[i].hoTen<<", Diem TB: "<< HS[i].diemTB<<", Xep loai: "<< HS[i].xepLoai<< "\n";
        }
    }
    if (!ok)
        cout<<"Khong tim thay hoc sinh nao\n";
}

int main()
{
    n=3;
    for (int i=1; i<=n; i++)
    {
        if(i>1)
            cin.ignore();
        cout<<"Nhap thong tin hoc sinh thu "<<i<<"\n";
        do
        {
            cout<<"Ho ten: ";
            getline(cin, HS[i].hoTen);
        } while(!checkten(HS[i].hoTen));
        cout<<"Diem Toan: ";
        HS[i].diemToan = nhap();
        cout<<"Diem Van: ";
        HS[i].diemVan = nhap();
        cout<<"Diem Anh: ";
        HS[i].diemAnh = nhap();
        Diemtb(HS[i]);
        xeploaihs(HS[i]);
        
    }
    int p=1;
    for(int i=2;i<=n;i++)
        if (HS[i].diemTB > HS[p].diemTB) 
            p=i;
    cout<<"\nHoc sinh co diem trung binh cao nhat la: "<<HS[p].hoTen<<" voi diem TB: " <<HS[p].diemTB<<"\n\n";
    cout<<"Danh sach hoc sinh:\n";
    for(int i=1;i<=n;i++)
        cout<<"Ho ten: " <<HS[i].hoTen<< ", Diem TB: " <<HS[i].diemTB<<", Xep loai: "<<HS[i].xepLoai<<"\n";
    float ngutoan=HS[1].diemToan;
    for (int i = 2; i <= n; i++)
        if (HS[i].diemToan < ngutoan) 
            ngutoan = HS[i].diemToan;
    cout<<"\nHoc sinh co diem toan thap nhat la:\n";
    for (int i=1;i<=n;i++)
        if (HS[i].diemToan==ngutoan)
            cout<<HS[i].hoTen<<" voi diem Toan: "<<HS[i].diemToan<<"\n";
    cout<<"\nNhap ten de tim kiem: ";
    string keyword;
    cin.ignore();
    getline(cin, keyword);
    Timten(keyword);
    return 0;
}
