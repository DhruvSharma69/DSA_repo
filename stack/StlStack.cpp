#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack <int> s;   //creating stack named s

    for(int i=1; i<11; i++)
    {
        s.push(i);              //inserting values in stack
    }

    for(int i=1; i<10; i++)
    {
        cout<<s.top()<<endl;             //printing top value
        s.pop();              //removing values in stack
    }

    cout<<" the last remaining element :  "<<s.top();
    
    return 0;

}
