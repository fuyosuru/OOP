#include<bits/stdc++.h>
using namespace std;

class GiaSuc{
protected:
    int sl;
    static int sosua;
public:
    GiaSuc(int sl);
    int getsl();
    static int getsosua();
};

class Bo:public GiaSuc{
public:
    Bo(int sl);
    string keu();
    void chosua();
    void sinhcon();
};

class Cuu:public GiaSuc{
public:
    Cuu(int sl);
    string keu();
    void chosua();
    void sinhcon();
};

class De:public GiaSuc{
public:
    De(int sl);
    string keu();
    void chosua();
    void sinhcon();
};
