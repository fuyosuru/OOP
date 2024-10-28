#include "hocsinh.cpp"
int n;
ThiSinh hs[30000];
int main()
{
    
    std::cout<<"nhap so hoc sinh: ";
    std::cin>>n;
    for(int i=1;i<=n;i++)
        {
            std::cout<<"nhap thong tin hoc sinh thu "<<i<<":\n";
            hs[i].Nhap();
        }
    std::cout<<"danh sach hoc sinh:\n";
    for(int i=1;i<=n;i++)
        hs[i].Xuat();
    std::cout<<"danh sach hoc sinh co tong diem lon hon 15:\n";
    for(int i=1;i<=n;i++)
        if(hs[i].Tong()>15)
            hs[i].Xuat();
    std::cout<<"hoc sinh co diem cao nhat:\n";
    int m=0;
    for(int i=1;i<=n;i++)
        if(hs[i].Tong()>hs[m].Tong())
            m=i;
    hs[m].Xuat();
}