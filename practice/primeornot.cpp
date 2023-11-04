#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int num;
    cin>>num;
    for( int i=2; i<=sqrt(num); i++){
        if(num%i==0)
       { cout<<"not a prime \n";
       break;
       }
       else{
        cout<<"a prime\n";

       }
    }
    return 0;
          
}