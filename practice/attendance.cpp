#include<iostream>
using namespace std;
class subject
{
    public:
    int totalclass, present,per;
    void update(int &totalclass, int &present)
    {
        totalclass++;
        present+=present;
        this->per=(present/totalclass)*100;
    }

};
class lab : public subject{


};

int main()
{
    subject DCM ;
    subject DCCN ;
    subject TOC ;
    subject POC ;
    subject RO ;
    subject DBMS ;
    subject JAVa ;
    lab javaL,NPL,LINUX,DBMSL,WDL;
    int agg=DCM.per;

}