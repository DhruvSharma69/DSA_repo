#include<iostream>
using namespace std;
int main(){
    // int b,c,*c1=&c,*a=&b,d,*d1=&d;
    // cout<<"printing "<<*a<<endl;
    // cin>>b;
    // cout<<endl<<"printing again"<<*a;
    // cout<<endl<<"now again"<<*d1;

    cout<<" \n ****************\n";
    int array[5]={1,2,3,4,5};
    char ch[5]="abcd";
    int *poi= &array[0];
    char *cp = &ch[0];
    cout<<"*poi "<<*poi<<" \n array "<<array<<" \n ch "<<ch<<" \n *cp "<<*cp;
    cout<<"\n poi "<< poi<<"\n cp"<<cp;
    return 0;
}