#include<bits/stdc++.h>
using namespace std;

// Struct CHUYENBAY: Lưu trữ thông tin một chuyến bay với mã chuyến bay, điểm khởi hành, điểm đến, ngày tháng năm và giờ bay.
struct CHUYENBAY
{
    string maCB,start,end;
    int ngay,thang,nam,gio,phut;
};

CHUYENBAY mangchuyenbay[100];
int n;

bool checkmaCB(string ma)
{
    // Hàm kiểm tra mã chuyến bay hợp lệ: 
    // Đầu vào là mã chuyến bay (string).
    // Đầu ra là true nếu mã hợp lệ (<=5 ký tự và là ký tự chữ hoặc số).
    if(ma.size()>5) 
        return false;
    for(int i=0; i<ma.size(); i++)
        if(!isalnum(ma[i])) 
            return false;
    return true;
}

bool checkdiem(string dia)
{
    // Hàm kiểm tra tên điểm đi/điểm đến hợp lệ: 
    // Đầu vào là tên địa điểm (string).
    // Đầu ra là true nếu hợp lệ (<=20 ký tự và chỉ chứa chữ cái và khoảng trắng).
    if(dia.size()>20) 
        {
            cout<<"Ten dia diem nay qua dai. Vui long nhap lai\n";
            return false;
        } 
    for(int i=0; i<dia.size(); i++)
        if(!isalpha(dia[i]) && dia[i]!=' ') 
            {
                cout<<"Ten dia diem nay khong hop le. Vui long nhap lai\n";
                return false;
            } 
    return true;
}

bool checkngay(int ngay, int thang, int nam)
{
    // Hàm kiểm tra ngày hợp lệ: 
    // Đầu vào là ngày, tháng, năm.
    // Đầu ra là true nếu ngày hợp lệ.
    if(nam<0 || thang<1 || thang>12 || nam>3000) 
        {
            cout<<"Ngay nay khong hop le. Vui long nhap lai\n";
            return false;
        } 
    int ngay_trong_thang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((nam%400==0) || (nam%4==0 && nam%100!=0)) 
        ngay_trong_thang[2]=29;
    if(ngay<1 || ngay>ngay_trong_thang[thang])
    {
        cout<<"Ngay nay khong hop le. Vui long nhap lai\n";
        return false;
    } 
    return true;
}

bool checkgio(int gio,int phut)
{
    // Hàm kiểm tra giờ hợp lệ: 
    // Đầu vào là giờ và phút. 
    // Đầu ra là true nếu giờ hợp lệ.
    if(gio<0 || gio>23 || phut<0 || phut>59) 
        {
            cout<<"Gio nay khong hop le. Vui long nhap lai\n";
            return false;
        } 
    return true;
}

void nhapCB()
{
    // Hàm nhập thông tin chuyến bay: 
    for(int i=1;i<=n;i++)
    {
        cout<<"Nhap thong tin chuyen bay "<<i<<":\n";
        do
        {
            cout<<"Ma chuyen bay: "; 
            cin>>mangchuyenbay[i].maCB;
        } while(!checkmaCB(mangchuyenbay[i].maCB));

        do
        {
            cout<<"Ngay bay (dd/mm/yyyy): "; 
            cin>>mangchuyenbay[i].ngay>>mangchuyenbay[i].thang>>mangchuyenbay[i].nam;
        } while(!checkngay(mangchuyenbay[i].ngay, mangchuyenbay[i].thang, mangchuyenbay[i].nam));

        do
        {
            cout<<"Gio bay (hh:mm): "; 
            cin>>mangchuyenbay[i].gio>>mangchuyenbay[i].phut;
        } while(!checkgio(mangchuyenbay[i].gio, mangchuyenbay[i].phut));
        cin.ignore(); 
        do
        {
            cout<<"Noi di: "; 
            getline(cin, mangchuyenbay[i].start);
        } while(!checkdiem(mangchuyenbay[i].start));

        do
        {
            cout<<"Noi den: "; 
            getline(cin, mangchuyenbay[i].end);
        } while(!checkdiem(mangchuyenbay[i].end));
    }
}

void xuatCB(CHUYENBAY cb)
{
    // Hàm xuất thông tin chuyến bay: 
    // Đầu vào là một chuyến bay (struct). 
    printf("Ma chuyen bay: %s, Ngay bay : %02d/%02d/%02d, Gio bay: %02d:%02d, Noi di: %s, Noi den: %s\n",cb.maCB.c_str(),cb.ngay,cb.thang,cb.nam,cb.gio,cb.phut,cb.start.c_str(),cb.end.c_str());
}

void xepCB()
{
    // Hàm sắp xếp các chuyến bay theo ngày giờ bay: 
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(mangchuyenbay[i].nam>mangchuyenbay[j].nam || (mangchuyenbay[i].nam==mangchuyenbay[j].nam && mangchuyenbay[i].thang>mangchuyenbay[j].thang) || (mangchuyenbay[i].nam==mangchuyenbay[j].nam && mangchuyenbay[i].thang==mangchuyenbay[j].thang && mangchuyenbay[i].ngay>mangchuyenbay[j].ngay) || (mangchuyenbay[i].nam==mangchuyenbay[j].nam && mangchuyenbay[i].thang==mangchuyenbay[j].thang && mangchuyenbay[i].ngay==mangchuyenbay[j].ngay && (mangchuyenbay[i].gio>mangchuyenbay[j].gio || (mangchuyenbay[i].gio==mangchuyenbay[j].gio && mangchuyenbay[i].phut>mangchuyenbay[j].phut))))
                swap(mangchuyenbay[i], mangchuyenbay[j]);
}

void timCB_ma(string Ma)
{
    // Hàm tìm chuyến bay theo mã: 
    // Đầu vào là mã chuyến bay.
    // Xuất các chuyến bay tìm được ra màn hình 
    bool ok = false;
    for(int i=1;i<=n;i++)
        if(mangchuyenbay[i].maCB==Ma)
        {
            xuatCB(mangchuyenbay[i]);
            ok=true;
        }
    if(!ok) 
        cout<<"Khong tim thay chuyen bay phu hop!\n";
}

void timCB_noidi(string Ma)
{
    // Hàm tìm chuyến bay theo điểm khởi hành: 
    // Đầu vào là điểm khởi hành. 
    // Xuất các chuyến bay tìm được ra màn hình 
    bool ok = false;
    for(int i=1;i<=n;i++)
        if(mangchuyenbay[i].start==Ma)
        {
            xuatCB(mangchuyenbay[i]);
            ok=true;
        }
    if(!ok) 
        cout<<"Khong tim thay chuyen bay phu hop!\n";
}

void timCB_noiden(string Ma)
{
    // Hàm tìm chuyến bay theo điểm đến: 
    // Đầu vào là điểm đến. 
    // Xuất các chuyến bay tìm được ra màn hình 
    bool ok = false;
    for(int i=1;i<=n;i++)
        if(mangchuyenbay[i].end==Ma)
        {
            xuatCB(mangchuyenbay[i]);
            ok=true;
        }
    if(!ok) 
        cout<<"Khong tim thay chuyen bay phu hop!\n";
}
void timCB_noidi_ngay(string start,int ngay,int thang,int nam)
{
    // Hàm timCB_noidi_ngay:
    // Đầu vào start (nơi khởi hành), ngay (ngày), thang (tháng), nam (năm).
    // Xuất các chuyến bay tìm được ra màn hình 
    bool ok = false;
    for(int i=1;i<=n;i++)
        if(mangchuyenbay[i].start==start && mangchuyenbay[i].ngay==ngay && mangchuyenbay[i].thang==thang && mangchuyenbay[i].nam==nam) 
        {
            xuatCB(mangchuyenbay[i]);
            ok=true;
        }
    if(!ok) 
        cout<<"Khong tim thay chuyen bay phu hop!\n";
}

int demCB(string start, string end)
{
    // Hàm demCB:
    // Đầu vào: start (nơi khởi hành), end (nơi đến).
    // Mục đích: Đếm số chuyến bay từ một nơi khởi hành cụ thể đến một nơi đến và xuất ra màn hình.
    int c = 0;
    for(int i=1;i<=n;i++)
        if(mangchuyenbay[i].start==start && mangchuyenbay[i].end==end) 
            c++;
    return c;
}

int main()
{
    int op;
    do
    {
        cout<<"1. Nhap thong tin chuyen bay\n";
        cout<<"2. Xuat danh sach chuyen bay\n";
        cout<<"3. Tim chuyen bay theo ma\n";
        cout<<"4. Tim chuyen bay theo noi di\n";
        cout<<"5. Tim chuyen bay theo noi den\n";
        cout<<"6. Tim chuyen bay theo noi di va ngay bay\n";
        cout<<"7. Dem so chuyen bay tu noi di den noi den\n";
        cout<<"8. Thoat\n";
        cout<<"Lua chon cua ban la: ";
        cin>>op;

        switch (op)
        {
        case 1:
            cout<<"Nhap so luong chuyen bay: ";
            cin>>n;
            nhapCB();
            xepCB();
            break;
        case 2:
            cout<<"\nDanh sach chuyen bay sau khi sap xep:\n";
            for (int i = 1; i <= n; i++)
                xuatCB(mangchuyenbay[i]);
            break;
        case 3:
        {
            string Ma;
            cout<<"\nNhap ma chuyen bay de tim kiem: ";
            cin.ignore();
            getline(cin, Ma);
            timCB_ma(Ma);
            break;
        }
        case 4:
        {
            string Ma;
            cout<<"\nNhap noi di cua chuyen bay de tim kiem: ";
            cin.ignore();
            getline(cin, Ma);
            timCB_noidi(Ma);
            break;
        }
        case 5:
        {
            string Ma;
            cout<<"\nNhap noi den cua chuyen bay de tim kiem: ";
            cin.ignore();
            getline(cin, Ma);
            timCB_noiden(Ma);
            break;
        }
        case 6:
        {
            string start;
            int ng, t, n;
            cout<<"\nNhap noi di: ";
            cin.ignore();
            getline(cin, start);
            cout<<"Nhap ngay bay:  ";
            cin>>ng>>t>>n;
            timCB_noidi_ngay(start, ng, t, n);
            break;
        }
        case 7:
        {
            string start, end;
            cin.ignore();
            cout<<"\nNhap noi di: ";
            getline(cin, start);
            cout<<"Nhap noi den: ";
            getline(cin, end);
            int soLuong = demCB(start, end);
            cout<<"So chuyen bay tu "<< start<<" den "<<end<<": "<<soLuong<<"\n";
            break;
        }
        case 8:
            cout<<"Bye Bye.\n";
            break;
        default:
            cout<<"Lua chon khong hop le. Vui long chon lai.\n";
        }
        cout<<"\n\n\n";
    } while (op != 8);
}
