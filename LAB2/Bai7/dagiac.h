#include "diem.cpp"

class DaGiac{
    private:
        int n;
        Diem *Dinh;
    public:
        void Nhap();
        void Xuat();
        void TinhTien(float x,float y);
        void PhongTo(float k);
        void ThuNho(float k);
        void Quay(Diem x, float goc);
        float TinhDienTich();
        void SapXep();
};