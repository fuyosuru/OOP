class Diem{
    private:
        double iHoanh,iTung;
    public:
        Diem();
        Diem(double Hoanh,double Tung);
        Diem(const Diem &x);
        void Xuat();
        double GetTungDo();
        double GetHoanhDo();
        void SetTungDo(double x);
        void SetHoanhDo(double x);
        void TinhTien(double x,double y);
        void ThuNho(double x);
        void PhongTo(double x);
        void Quay(Diem x, double goc);
};