#include<iostream>
using namespace std;

class interest
{
    public:
    float amount=100000.0,sum,time,rate=2.7;
    void intr()
    {
        cout<<"enter no. of years "<<endl;
        cin>>time;
        for(int i=0;i<time;i++)
        {
            amount=amount+ (12*500);
            sum=amount+ (amount*rate/100);
            cout<<"for year  "<<1+i<<" the sum is "<<sum<<endl;
        }
        cout<<"final sum "<<sum;
    }


};
int main()
{
    interest cal;
    cal.intr();
    return 0;
}