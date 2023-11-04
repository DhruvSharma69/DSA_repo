#include<iostream>
using namespace std;
void a()
{
    cout<<" ----";
}
void b()
{
    cout<<"|";
}
void c()
{
    cout<<"|";
}
void d()
{
    cout<<" ----";
}
void e()
{
    cout<<"    |";
}
void f()
{
    cout<<"    |";
}
void g()
{
    cout<<" ----";
}
int main()
{
    int n;
    cin>>n;
    switch(n)
    {
        case 0:a();
        cout<<endl;
        b();
        f();
        
        cout<<endl;
        
        c();
        e();
        
        cout<<endl;
        d();
        cout<<endl;
        
        
        break;

        case 1:b();
        cout<<endl;
        c();
        break;
        case 8:a();
        cout<<endl;
        b();
        f();
        
        cout<<endl;
        g();
        cout<<endl;
        c();
        e();
        
        cout<<endl;
        d();
        cout<<endl;
        case 2:a();
        cout<<endl;
        f();
        cout<<endl;
        g();
        cout<<endl;
        c();
        cout<<endl;
        d();
        break;
        case 4:
        b();
        f();
        cout<<endl;
        g();
        cout<<endl;
        e();
        break;
        default:cout<<"enter correct ";
        
    }

    return 0;
}