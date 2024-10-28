#include<bits/stdc++.h>
#include "diem.cpp"
using namespace std;
int main()
{
    Diem y(1.3,2.6);
    y.Xuat();
    printf("Diem y co hoang do la %f va tung do la %f\n",y.GetHoanhDo(),y.GetTungDo());
    y.SetHoanhDo(3);
    y.SetTungDo(8);
    printf("Diem y sau khi thay doi co hoang do la %f va tung do la %f\n",y.GetHoanhDo(),y.GetTungDo());
    y.TinhTien(3,4);
    printf("Diem y sau khi tinh tien voi vector (3,4) co hoang do la %f va tung do la %f\n",y.GetHoanhDo(),y.GetTungDo());
}