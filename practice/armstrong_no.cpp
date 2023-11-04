#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,t; //t is the test variable on which we will perform all operation so that 'n' can remain orignal
    cin>>n;
    t=n;
    int fn=0;         //fn refers to final no. that is no which will be compared to n
    while(t>0)
    {
        fn= fn + pow(t%10,3);   //pow(no. , p) is syntax for writing no to power 'p'
        t=t/10;
        
    }
    cout<<fn;
    if(fn==n)
    cout<<"is armstrong no.";
      /*  armstrong no are no which remains the same if we add the cubes of all its digits.
       for ex: 153 ==> 1 cube + 5 cube +3 cube=153 */ 
    else
    cout<<"is not a armstrong no.";
}