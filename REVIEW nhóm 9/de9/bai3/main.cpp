#include <bits/bits-stdc++.h>  
using namespace std;

// Lớp cơ sở CaSy  
class CaSy {
protected:
    string HoTen; 
    int NamLamViec, DiaBanDuoc, BuoiTrinhDien; // Số năm làm việc, số địa bàn được, số buổi trình diễn  

public:
    CaSy() {} 
    ~CaSy() {} 
    virtual void Nhap(); 
    virtual void Xuat(); 
    virtual float TinhLuong() = 0; 
};

// Định nghĩa hàm Nhap của lớp CaSy  
void CaSy::Nhap() {
    cout << "Nhap thong tin ca sy:\n";
    cout << "Ho ten: ";
    cin.ignore();//Xóa bộ nhớ đệm
    getline(cin, HoTen);
    
    cout << "So nam lam viec: ";
    cin >> NamLamViec;   
    cout << "So dia ban duoc: ";
    cin >> DiaBanDuoc; 
    cout << "So buoi trinh dien: ";
    cin >> BuoiTrinhDien; 
}

// Định nghĩa hàm Xuat của lớp CaSy  
void CaSy::Xuat() {
    cout << "thong tin ca sy:\n";
    cout << "Ho ten: " << HoTen << "\n";  
    cout << "So nam lam viec: " << NamLamViec << "\n";  
    cout << "So dia ban duoc: " << DiaBanDuoc << "\n";   
    cout << "So buoi trinh dien: " << BuoiTrinhDien << "\n";  
}

// Lớp con CaSyChuaNoiTieng  
class CaSyChuaNoiTieng : public CaSy {
public:
    CaSyChuaNoiTieng() {} 
    ~CaSyChuaNoiTieng() {} 

    void Nhap() {
        CaSy::Nhap(); 
    }

    void Xuat() {
        CaSy::Xuat();  
    }
        // Tính lương cho ca sĩ chưa nổi tiếng 
    float TinhLuong() {
        return 3000000 + 500000 * NamLamViec + 1000 * DiaBanDuoc + 200000 * BuoiTrinhDien;
    }
};

// Lớp con CaSyNoiTieng  
class CaSyNoiTieng : public CaSy {
protected:
    int GameShow; 

public:
    CaSyNoiTieng() {} 
    ~CaSyNoiTieng() {} 

    void Nhap() {
        CaSy::Nhap(); 
        cout << "So luong gameshow tham gia: ";
        cin >> GameShow; 
    }

    void Xuat() {
        CaSy::Xuat(); 
        cout << "So luong gameshow tham gia: " << GameShow << "\n"; 
    }
      // Tính lương cho ca sĩ nổi tiếng  
    float TinhLuong() {
        
        return 5000000 + 500000 * NamLamViec + 1200 * DiaBanDuoc + 500000 * BuoiTrinhDien + 500000 * GameShow;
    }
};

int main() {
   
    // Nhập số lượng ca sĩ  
    cout << "Nhap so luong ca sy: ";
    int SoLuongCaSy;
    cin >> SoLuongCaSy; 
    
    CaSy** arr = new CaSy * [SoLuongCaSy]; // Mảng con trỏ để lưu trữ thông tin các ca sĩ  

    for (int i = 0; i < SoLuongCaSy; i++) {
        cout << "1. Ca sy chua noi tieng\n2. Ca sy noi tieng\n"; // Lựa chọn loại ca sĩ  
        int loai;
        cin >> loai; // Nhập loại ca sĩ  
        if (loai == 1) {
            arr[i] = new CaSyChuaNoiTieng(); // Tạo đối tượng ca sĩ chưa nổi tiếng  
        }
        else if (loai == 2) {
            arr[i] = new CaSyNoiTieng(); // Tạo đối tượng ca sĩ nổi tiếng  
                }
        else if (loai != 1 && loai != 2)
        {
            while (loai != 1 && loai != 2) {
              cout << "Nhap khong hop le, nhap lai: ";
              cin >> loai;
             }
            if (loai == 1) {
                arr[i] = new CaSyChuaNoiTieng(); // Tạo đối tượng ca sĩ chưa nổi tiếng  
            }
            else if (loai == 2) {
                arr[i] = new CaSyNoiTieng(); // Tạo đối tượng ca sĩ nổi tiếng  
            }
        }
       
        arr[i]->Nhap(); 
    }

    // Tìm ca sĩ có lương cao nhất  
    float LuongCaoNhat = -1.0;  
    int pos = -1; 
    for (int i = 0; i < SoLuongCaSy; i++) {
        // So sánh để tìm ca sĩ có lương cao nhất  
        if (arr[i]->TinhLuong() > LuongCaoNhat) {
            LuongCaoNhat = arr[i]->TinhLuong(); 
            pos = i;  
        }
    }
    cout << "Ca sy co luong cao nhat la";
    arr[pos]->Xuat();

    // Giải phóng bộ nhớ đã cấp phát  
    for (int i = 0; i < SoLuongCaSy; i++) {
        delete arr[i];  
    }

    return 0; 
}
