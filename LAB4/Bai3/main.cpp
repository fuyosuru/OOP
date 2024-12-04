#include "giasuc.cpp"
int main()
{
    srand(time(NULL));
    mt19937 g(rand());
    vector<string> tiengkeu;
    int x,y,z;
    cout<<"Nhap so luong bo: ";
    cin>>x;
    cout<<"Nhap so luong de: ";
    cin>>y;
    cout<<"Nhap so luong cuu: ";
    cin>>z;
    Bo bo(x);
    Cuu cuu(y);
    De de(z);
    cout<<"Tieng keu khi doi:\n";
    for(int i=0;i<bo.getsl();i++)
        tiengkeu.push_back(bo.keu());
    for(int i=0;i<de.getsl();i++)
        tiengkeu.push_back(de.keu());
    for(int i=0;i<cuu.getsl();i++)
        tiengkeu.push_back(cuu.keu());
    shuffle(tiengkeu.begin(),tiengkeu.end(),g);
    for(auto i:tiengkeu)
        cout<<i;
    bo.chosua();
    bo.sinhcon();
    de.chosua();
    de.sinhcon();
    cuu.chosua();
    cuu.sinhcon();
    cout<<"Tong so bo sau khi sinh: "<<bo.getsl()<<"\n";
    cout<<"Tong so cuu sau khi sinh: "<<cuu.getsl()<<"\n";
    cout<<"Tong so de sau khi sinh: "<<de.getsl()<<"\n";
    cout<<"Tong so sua (truoc khi sinh): "<<GiaSuc::getsosua()<<"l"<<"\n";
    return 0;
}
