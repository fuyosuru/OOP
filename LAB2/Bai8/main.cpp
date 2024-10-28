#include "list.cpp"

int main()
{
    int n=1000;
    List ls;
    for(int i=1;i<=n;i++)
    {
        int x;
        std::cout<<"Nhap chi thi thu "<<i<<": ";
        std::cin>>x;
        if(x==0)
        {
            int y;
            std::cout<<"Nhap gia tri muon them vao list: ";
            std::cin>>y;
            ls.Them(y);
        }
        if(x==1)
        {
            int y;
            std::cout<<"Nhap gia tri muon xoa khoi list: ";
            std::cin>>y;
            ls.Xoa(y);
        }
        if(x==2)
        {
            int y;
            std::cout<<"Nhap gia tri muon xoa khoi list: ";
            std::cin>>y;
            ls.XoaHet(y);
        }
        if(x==3)
        {
            int y,z;
            std::cout<<"Nhap vi tri va gia tri: ";
            std::cin>>y>>z;
            ls.ThayDoi(y,z);
        }
        if(x==-1)
            break;
    }
    ls.Xuat();
}