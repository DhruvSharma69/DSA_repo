#include<iostream>
using namespace std;

int main()

{
     int n=5;
    int *p=&n;
   
    
    cout<<"printint *p "<< *p <<endl;
    cout<<"printint p "<< p <<endl;
    cout<<"printint &p "<< &p <<endl;
     int m=5;
    int *q=0;
    q=&m;

     cout<<"printint &m"<< &m <<endl;
     cout<<"printint *q "<< *q <<endl;
    cout<<"printint q "<< q <<endl;

    int o=5;
    int *r=0;
    //below code don't show error but also don't work at all on output terminal
    // *r=o;

    //  cout<<"printint &o"<< &o<<endl;
    //  cout<<"printint *r "<< *r <<endl;
    // cout<<"printint r "<< r<<endl;
    //copying a pointer
    int *s=p;
    cout<<"printint &p"<< &p<<endl;
     cout<<"printint *s "<< *s <<endl;
    cout<<"printint s "<< s<<endl;

    return 0;

}