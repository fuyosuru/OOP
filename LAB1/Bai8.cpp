#include<bits/stdc++.h>
using namespace std;

// Định nghĩa cấu trúc DATE để lưu trữ ngày tháng năm và thông tin năm nhuận.
struct DATE{
    int ngay, thang, nam;
    bool nhuan;
};

// Định nghĩa cấu trúc STK để lưu trữ thông tin tài khoản tiết kiệm.
struct STK{
    string ms, loai_tk, ten; // Mã số, loại tài khoản, tên chủ tài khoản
    long long cmnd;
    DATE ngay_mo; // Ngày mở tài khoản
    double tien,laixuat; // Số tiền gửi và lãi suất
};

int n;
int so_ngay[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; // Số ngày trong mỗi tháng
STK danhsach[300];

bool checknhuan(int nam)
{
    // Hàm kiểm tra năm nhuận
    // Đầu vào: năm (int)
    // Đầu ra: true nếu năm là năm nhuận, false nếu không
    return (nam%4==0 && (nam%100!=0 || nam%400==0));
}

bool checkngay(DATE date)
{
    // Hàm kiểm tra tính hợp lệ của ngày tháng
    // Đầu vào: date (DATE)
    // Đầu ra: true nếu ngày hợp lệ, false nếu không
    if(checknhuan(date.nam))
        so_ngay[2]=29;
    if(date.thang<1 || date.thang>12 || date.ngay<1 || date.ngay>so_ngay[date.thang])
        return 0;
    return 1;
}

long long encode(int day, int mon, int year) 
{
    // Hàm mã hóa ngày tháng năm thành số ngày kể từ năm 1
    // Đầu vào: ngày (int), tháng (int), năm (int)
    // Đầu ra: tổng số ngày (long long)
    long long total_days = 0;
    for (int y = 1; y < year; ++y) 
        total_days += checknhuan(y) ? 366 : 365;
    for (int m = 1; m < mon; ++m) 
        total_days += so_ngay[m];
    total_days+=day;
    return total_days;
}

int songay(DATE d1, DATE d2)
{
    // Hàm tính số ngày giữa hai ngày
    // Đầu vào: d1 (DATE), d2 (DATE)
    // Đầu ra: số ngày giữa d1 và d2 (int)
    int enc1=encode(d1.ngay,d1.thang,d1.nam);
    int enc2=encode(d2.ngay,d2.thang,d2.nam);
    return (enc1-enc2);
}

void xuatngay(DATE date)
{
    // Hàm xuất ngày theo định dạng dd/mm/yyyy
    // Đầu vào: date (DATE)
    // Xuất ngày này ra màn hình
    printf("%02d/%02d/%d",date.ngay,date.thang,date.nam);
}

void xuatstk(STK stk)
{
    // Hàm xuất thông tin tài khoản
    // Đầu vào: stk (STK)
    // Xuất thông tin của sổ tiết kiệm này ra màn hình
    cout<<"Ma so: "<<stk.ms<<", Loai: "<<stk.loai_tk<<", Ho ten: "<<stk.ten<<", CMND: "<<stk.cmnd<<", Lai xuat: "<<stk.laixuat<<", Ngay mo: "; 
    xuatngay(stk.ngay_mo);
    cout<<", So tien gui: "<<stk.tien<<"\n";
}

bool checkmaso(string ms)
{
    // Hàm kiểm tra tính hợp lệ của mã số tài khoản
    // Đầu vào: ms (string)
    // Đầu ra: true nếu hợp lệ, false nếu không
    if (ms.size()>5)
        {
            cout<<"Ma so khong hop le!\n";
            return 0;
        }
    for(auto c: ms)
        if(!isalnum(c))
            {
                cout<<"Ma so khong hop le!\n";
                return 0;
            }
    return 1;
}

bool checkloai(string loai)
{
    // Hàm kiểm tra tính hợp lệ của loại tài khoản
    // Đầu vào: loai (string)
    // Đầu ra: true nếu hợp lệ, false nếu không
    if (loai.size()>10)
        {
            cout<<"loai tai khoan khong hop le!\n";
            return 0;
        }
    for(auto c: loai)
        if(!isalnum(c) && c!=' ')
            {
                cout<<"loai tai khoan khong hop le!\n";
                return 0;
            }
    return 1;
}

bool checkten(string ten)
{
    // Hàm kiểm tra tính hợp lệ của tên chủ tài khoản
    // Đầu vào: ten (string)
    // Đầu ra: true nếu hợp lệ, false nếu không
    if (ten.size()>30)
        {
            cout<<"ten chu tai khoan khong hop le!\n";
            return 0;
        }
    for(auto c: ten)
        if(!isalnum(c) && c!=' ')
            {
                cout<<"ten chu tai khoan khong hop le!\n";
                return 0;
            }
    return 1;
}

bool checkcmnd(long long cmnd)
{
    // Hàm kiểm tra tính hợp lệ của số CMND
    // Đầu vào: cmnd (long long)
    // Đầu ra: true nếu hợp lệ, false nếu không
    int len=to_string(cmnd).length();
    if(len==9 || len==12)
        return 1;
    cout<<"CMND khong hop le!\n";
    return 0;
}

double tinhlai(DATE start,int cmnd)
{
    // Hàm tính toán lãi suất cho một tài khoản
    // Đầu vào: start (DATE), cmnd (int)
    // Đầu ra: số lãi suất tính được (double)
    STK stk;
    stk.tien=0;
    double lai;
    for(int i=1;i<=n;i++)
        if(danhsach[i].cmnd==cmnd)
            stk=danhsach[i];
    if(stk.tien==0)
        cout<<"CMND nay khong ton tai.";
    lai=stk.laixuat;
    int so_ngay_gui=songay(start,stk.ngay_mo);
    double nhan_duoc=lai;
    if(stk.loai_tk=="ngan han" && so_ngay_gui>180)
        nhan_duoc=0.5;
    else 
        if(stk.loai_tk=="dai han" && so_ngay_gui<=180)
            nhan_duoc=0.5;
    return (stk.tien*nhan_duoc*so_ngay_gui)/(365);
}

STK nhapstk() 
{
    // Hàm nhập thông tin tài khoản
    // Đầu vào: không có
    // Đầu ra: stk (STK) - thông tin tài khoản
    STK stk;
    DATE ngaymo;
    cin.ignore();
    do{
        cout<<"Nhap ma so: ";
        getline(cin, stk.ms);
    }while(!checkmaso(stk.ms));
    do{
        cout<<"Nhap loai so: ";
        getline(cin, stk.loai_tk);
    }while(!checkloai(stk.loai_tk));
    do{
        cout<<"Nhap ten chu tai khoan: ";
        getline(cin, stk.ten);
    }while(!checkten(stk.ten));
    do{
        cout<<"Nhap CMND: ";
        cin>>stk.cmnd;
    }while(!checkcmnd(stk.cmnd));
    do{
        cout<<"Nhap ngay mo so (dd mm yyyy): ";
        cin>>ngaymo.ngay>>ngaymo.thang>>ngaymo.nam;
        stk.ngay_mo=ngaymo;
    }while(!checkngay(ngaymo));
    do{
        cout<<"Nhap so tien: ";
        cin>>stk.tien;
    }while(stk.tien<0);
    do{
        cout<<"Nhap lai xuat: ";
        cin>>stk.laixuat;
    }while(stk.laixuat<0);
    return stk;
}

void ruttien(int cmnd,int so_tien_rut,DATE start)
{
    // Hàm rút tiền
    // Đầu vào: số CMND của sổ tiết kiệm cần rút và ngày mặc định (1/1/1)
    // Mục đích: thực hiện thao tác rút tiền, cảnh báo nếu rút trước kỳ hạn
    int pos=0;
    double lai;
    for(int i=1;i<=n;i++)
        if(danhsach[i].cmnd==cmnd)
            pos=i;
    if(pos==0)
        cout<<"CMND nay khong ton tai.";
    if(songay(danhsach[pos].ngay_mo, start)<180)
        cout<<"Rut truoc han! Lai suat ap dung se bi giam.\n";
    danhsach[pos].tien-=so_tien_rut;
    cout<<"Tai khoan cua ban con "<<danhsach[pos].tien<<" dong";
}

void Timso_cmnd(int cmnd) 
{
    // Hàm tìm sổ tiết kiệm theo số CMND
    // Đầu vào: số CMND của sổ tiết kiệm cần tìm
    // Mục đích: xuất ra thông tin của số tiết kiệm cần tìm
    int pos=0;
    for(int i=1;i<=n;i++)
        if(danhsach[i].cmnd==cmnd)
        {
            pos=i;
            xuatstk(danhsach[i]);
        }
    if(pos==0)
        cout<<"So CMND khong ton tai.";
}

void Timso_ms(string ms) 
{
    // Hàm tìm sổ tiết kiệm theo mã sổ
    // Đầu vào: mã sổ của sổ tiết kiệm cần tìm
    // Mục đích: xuất ra thông tin của số tiết kiệm cần tìm
    int pos=0;
    for(int i=1;i<=n;i++)
        if(danhsach[i].ms==ms)
        {
            pos=i;
            xuatstk(danhsach[i]);
        }
    if(pos==0)
        cout<<"Ma so khong ton tai.";
}

void Timso_ngay(DATE x,DATE y)
{
    // Hàm tìm sổ tiết kiệm được mở trong thời khoảng thời gian cho trước
    // Đầu vào: DATE x,y. Khoảng thời gian (từ ngày x đến ngày y) 
    // Mục đích: xuất ra thông tin của những số tiết kiệm có ngày mở sổ trong khoảng thời gian cho trước
    int pos=0;
    for(int i=1;i<=n;i++)
        if(songay(danhsach[i].ngay_mo,x)>=0 && songay(y,danhsach[i].ngay_mo)>=0)
        {
            pos=i;
            xuatstk(danhsach[i]);
        }
    if(pos==0)
        cout<<"Khong tim thay ket qua phu hop.";
}

bool cmptien(STK a,STK b)
{
    // Hàm so sánh 2 sổ tiết kiệm
    // Đầu vào: STK a,b. 2 sổ tiết kiệm a,b
    // Mục đích: Trả về true nếu số tiền của sổ tiết kiệm a ít tiền hơn sổ tiết kiệm b, False trong trường hợp ngược lại
    return a.tien<b.tien;
}

bool cmpngay(STK a,STK b)
{
    // Hàm so sánh 2 sổ tiết kiệm
    // Đầu vào: STK a,b. 2 sổ tiết kiệm a,b
    // Mục đích: Trả về true nếu số tiền của sổ tiết kiệm a mở trước sổ tiết kiệm b, False trong trường hợp ngược lại
    return songay(a.ngay_mo, DATE{1,1,1})<songay(b.ngay_mo, DATE{1,1,1});
}

int main()
{
    
    DATE homnay;
    homnay.ngay=9;
    homnay.thang=10;
    homnay.nam=2024;
    cout<<"nhap so luong so tiet kiem: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Nhap thong tin cua so tiet kiem thu "<<i<<":\n";
        danhsach[i]=nhapstk();
    }
    cout<<"Danh sach cac so tiet kiem da nhap:\n";
    for(int i=1;i<=n;i++)
        xuatstk(danhsach[i]);
    sort(danhsach+1, danhsach+n+1, cmptien);
    cout<<"\n\nDanh sach sap xep theo so tien:\n";
    for(int i=1;i<=n;i++)
        xuatstk(danhsach[i]);
    sort(danhsach+1, danhsach+n+1, cmpngay);
    cout<<"\n\nDanh sach sap xep theo ngay mo so:\n";
    for(int i=1;i<=n;i++)
        xuatstk(danhsach[i]);
    int op;
    do
    {
        cout<<"1. Tim so tiet kiem theo CMND\n";
        cout<<"2. Tim so tiet kiem theo ma so\n";
        cout<<"3. Liet ke cac so tiet kiem trong mot khoang thoi gian\n";
        cout<<"4. Tinh toan tien lai\n";
        cout<<"5. Rut tien\n";
        cout<<"6. Thoat\n";
        cout<<"Lua chon cua ban la: ";
        cin>>op;

        switch(op)
        {
        case 1:
        {
            cout<<"Nhap CMND: ";
            int x;
            cin>>x;
            Timso_cmnd(x);
            break;
        }
        case 2:
        {
            cout << "Nhap ma so: ";
            string maso;
            cin.ignore();
            getline(cin,maso);
            Timso_ms(maso);
            break;
        }
        case 3:
        {
            DATE start,end;
            cout<<"Nhap khoang thoi gian can tim (dd/mm/yyyy dd/mm/yyyy): ";
            cin>>start.ngay>>start.thang>>start.nam>>end.ngay>>end.thang>>end.nam;
            Timso_ngay(start,end);
            break;
        }
        case 4:
        {
            int cm;
            cout<<"Nhap CMND de tinh tien lai: ";
            cin>>cm;
            cout<<"Tien lai: ";
            cout<<tinhlai(homnay,cm);
            break;
        }
        case 5:
        {
            int cm,tien;
            cout<<"Nhap CMND va so tien de rut: ";
            cin>>cm>>tien;
            ruttien(cm,tien,homnay);
            break;
        }
        case 6:
        {
            cout<<"Bye bye.";
            break;
        }
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
        cout<<"\n\n\n";
    } while (op != 6);
}
