#include<iostream>
#include<stack>
using namespace std;

stack <int> Push_Bottom(stack <int> &s, int b)
{
    if(s.empty())
    {
        
        s.push(b);
        return s;
    }
    else
    {
        int c = s.top();
        s.pop();
        s = Push_Bottom(s,b);
        s.push(c);
        
    }

    return s;

}
int main()
{
    stack <int> s;
    for(int i=0; i<4; i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }
    cout<<" enter the no. \n ";
        int b;
        cin>>b;
    stack <int> ans = Push_Bottom(s,b);
    while(!ans.empty())
    
    {
        cout<<ans.top();
        ans.pop();
    }
    return 0;
}
