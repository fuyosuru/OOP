#include "diem.cpp"

int main(){
    float hoanh,tung;
    std::cout<<"Nhap hoanh do: ";
    std::cin>>hoanh;
    std::cout<<"Nhap tung do: ";
    std::cin>>tung;
    Diem diem(hoanh,tung);
    int n;
    std::cout<<"Nhap so luong chi thi: ";
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        std::cout<<"Nhap chi thi "<<i+1<<": ";
        std::cin>>x;
        if(x==1)
        {
            diem.SetHoanhDo(diem.GetHoanhDo()*2);
            diem.SetTungDo(diem.GetTungDo()*2);
        }
        else 
            if(x==2)
            {
                diem.SetHoanhDo(0);
                diem.SetTungDo(0);
            }
            else 
            if(x==3)
            {
                int k;
                float d;
                std::cout<<"Nhap huong tinh tien k (0: theo x, 1: theo y): ";
                std::cin>>k;
                std::cout<<"Nhap do tinh tien d: ";
                std::cin>>d;
                if(k==0)
                    diem.TinhTien(d,0);
                else
                    diem.TinhTien(0,d);
            }
    }
    std::cout<<"Toa do cuoi cung cua diem la: ";
    diem.Xuat();
    return 0;
}