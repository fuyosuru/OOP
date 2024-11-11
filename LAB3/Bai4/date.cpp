#include "date.h"
int doingay(int thang,int nam)
{
    //Hàm tính số ngày trong tháng với tháng và năm được cho
    //Đầu vào: tháng và năm
    //Đầu ra: số ngày trong tháng của tháng và năm đã nhập vào
    int Ngay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(thang==2 && ((nam%4==0 && nam%100!=0) || nam%400==0))
        return 29; 
    return Ngay[thang-1];
}

NgayThangNam::NgayThangNam()
{
    //Contructor mặc định: khởi tạo ngày tháng năm 1/1/2000
    iNgay=1;
    iThang=1;
    iNam=2000;
}

NgayThangNam::NgayThangNam(int Ngay,int Thang,int Nam)
{
    //Contructor mặc định: khởi tạo ngày tháng năm với ngày tháng năm đã cho
    iNam=Nam;
    iThang=Thang;
    iNgay=Ngay;
}

NgayThangNam NgayThangNam::operator +(int Ngay)
{
    //Hàm tính xem ngày tháng năm mới sau khi được cộng thêm n ngày (n là số ngày đã nhập)
    /* Ý tưởng chính: tăng số ngày lên nếu số ngày vượt quá số ngày trong tháng 
    thì tăng tháng lên tương tự cho năm */
    //Đầu vào: số ngày cần tăng
    //Đầu ra: ngày tháng năm mới sau khi đã tăng
    NgayThangNam result=*this;
    result.iNgay+=Ngay;
    while(result.iNgay>doingay(result.iThang,result.iNam))
    {
        result.iNgay-=doingay(result.iThang,result.iNam);
        result.iThang++;
        if(result.iThang>12)
        {
            result.iThang=1;
            result.iNam++;
        }
    }
    return result;
}

NgayThangNam NgayThangNam::operator -(int Ngay)
{
    //Hàm tính xem ngày tháng năm mới sau khi bị trừ đi n ngày (n là số ngày đã nhập)
    /* Ý tưởng chính: giảm số ngày xuống nếu số ngày về 0 thì giảm tháng xuống và làm mới số ngày
    bằng số ngày trong tháng mới tương tự cho năm */
    //Đầu vào: số ngày cần tăng
    //Đầu ra: ngày tháng năm mới sau khi đã giảm
    NgayThangNam result=*this;
    result.iNgay-=Ngay;
    while(result.iNgay<=0)
    {
        result.iThang--;
        if(result.iThang<=0)
        {
            result.iThang=12;
            result.iNam--;
        }
        result.iNgay+=doingay(result.iThang,result.iNam);
    }
    return result;
}

NgayThangNam NgayThangNam::operator -(NgayThangNam a)
{
    //Hàm tính xem ngày tháng năm mới sau khi bị trừ đi một khoảng thời gian
    /* Ý tưởng chính: giảm số ngày xuống nếu số ngày về 0 thì giảm tháng xuống và làm mới số ngày
    bằng số ngày trong tháng mới tương tự cho năm. Sau đó làm tương tự để giảm tháng. Cuối cùng là giảm năm*/
    //Đầu vào: khoảng thời gian muốn trừ đi
    //Đầu ra: ngày tháng năm mới sau khi đã giảm
    NgayThangNam result=*this;
    result.iNgay-=a.iNgay;
    result.iNam-=a.iNam;
    result.iThang-=a.iThang;
    while(result.iThang<=0)
    {
        result.iNam--;
        result.iThang+=12;
    }
    while(result.iNgay<=0)
    {
        result.iThang--;
        if(result.iThang<=0)
        {
            result.iThang=12;
            result.iNam--;
        }
        result.iNgay+=doingay(result.iThang,result.iNam);
    }
    return result;
}

NgayThangNam NgayThangNam::operator ++()
{
    *this=*this+1;
    return *this;
}

NgayThangNam NgayThangNam::operator ++(int)
{
    NgayThangNam temp=*this;
    *this=*this+1;
    return temp;
}

NgayThangNam NgayThangNam::operator --()
{
    *this=*this-1;
    return *this;
}

NgayThangNam NgayThangNam::operator --(int)
{
    NgayThangNam temp=*this;
    *this=*this-1;
    return temp;
}

int NgayThangNam::TinhNgay()
{
    int res=0;
    for(int i=1;i<iThang;i++)
        res+=doingay(i,iNam);
    res+=iNgay;
    return res;
}

bool NgayThangNam::operator ==(NgayThangNam b)
{
    return iNgay==b.iNgay && iThang==b.iThang && iNam==b.iNam;
}

bool NgayThangNam::operator !=(NgayThangNam b)
{
    return !(*this==b);
}

bool NgayThangNam::operator >=(NgayThangNam b)
{
    return iNam>b.iNam || (iNam==b.iNam && (iThang>b.iThang || (iThang==b.iThang && iNgay>=b.iNgay)));
}

bool NgayThangNam::operator <=(NgayThangNam b)
{
    return iNam<b.iNam || (iNam==b.iNam && (iThang<b.iThang || (iThang==b.iThang && iNgay<=b.iNgay)));
}

bool NgayThangNam::operator >(NgayThangNam b)
{
    return !(*this<=b);
}

bool NgayThangNam::operator <(NgayThangNam b)
{
    return !(*this>=b);
}

istream& operator >>(istream& is,NgayThangNam& a)
{
    is>>a.iNgay>>a.iThang>>a.iNam;
    return is;
}

ostream& operator <<(ostream& os,NgayThangNam a)
{
    int res=a.iNam;
    string suffix="";
    if(a.iNam<1)
    {
        res=abs(a.iNam-1);
        suffix=" TCN";
    }
    os<<a.iNgay<<"/"<<a.iThang<<"/"<<res<<suffix;
    return os;
}
