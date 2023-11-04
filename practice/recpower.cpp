#include<iostream>
using namespace std;
int power(int& n,int p)
{
    if(p==0)
    return 1;
    else
    {
        return n*power(n,(p-1));
    }
}
 int main()
 {
    cout<<"enter no. to find power \n";
    int n;
    cin>>n;
    cout<<"tner power \n";
    int p;
    cin>>p;
    int ans=power(n,p);
    cout<<ans;
    return 0;
 }