#include<iostream>
using namespace std;

class first
{
    public:
    int a , b;
    int disadd()
    {
        cout<<"enter no1,no2"<<endl;
        cin>>a>>b;
        cout<<a+b;
        return 0;

    }
    int dissub()
    {
        cout<<"enter no1,no2"<<endl;
        cin>>a>>b;
        cout<<a-b;
        return 0;
        
    }
    int mult();
    
};
int first :: mult()
{
    cout<<"a,b"<<endl;
    cin>>a>>b;
    cout<<a*b;
return 0;
}
int main()
{
    first o;
    cout<<"calling mult \n";
    o.mult();
    cout<<"calling add \n";
    o.disadd();
return 0;
}
