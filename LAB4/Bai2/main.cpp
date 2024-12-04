#include "Phong.cpp"
int main()
{
    Deluxe a(2,2000,2000),b(3,2000,5000);
    Premium c(5,2000),d(3,5000);
    Business e(4);
    int Max=0;
    Max=max({Max,Deluxe::getmoneydeluxe(),Premium::getmoneypremium(),Business::getmoneybusiness()});
    cout<<"Looi phong co doanh thu cao nhat la:\n";
    if(Deluxe::getmoneydeluxe()==Max)
        cout<<"Deluxe: "<<Deluxe::getmoneydeluxe()<<"\n";
    if(Premium::getmoneypremium()==Max)
        cout<<"Premium: "<<Premium::getmoneypremium()<<"\n";
    if(Business::getmoneybusiness()==Max)
        cout<<"Business: "<<Business::getmoneybusiness()<<"\n";
    return 0;
}
