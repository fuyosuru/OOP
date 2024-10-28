class Diem{
    private:
        float iHoanh,iTung;
    public:
        Diem();
        Diem(float Hoanh,float Tung);
        Diem(const Diem &x);
        void Xuat();
        float GetTungDo();
        float GetHoanhDo();
        void SetTungDo(float x);
        void SetHoanhDo(float x);
        void TinhTien(float x,float y);
};