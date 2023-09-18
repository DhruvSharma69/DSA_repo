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

stack <int> Reversed(stack <int> &s)
{
    if(s.empty())
    return s;
    else
    {
        int a = s.top();
        s.pop();
       s =  Reversed(s);
       s = Push_Bottom(s,a);
    }
    return s;

}
int main()
{
    stack <int> s;
    for(int i=1;i<4;i++)
    {
        s.push(i);
    }
   
    cout<<" \n orignal \n ";
    for(stack<int> dump = s; !dump.empty(); dump.pop())
    {
        cout<<dump.top()<<" ";
    }
     stack <int> ans = Reversed(s);
    //Printing the values by popping one by one
    //  while(!ans.empty())
    
    // {
    //     cout<<ans.top();
    //     ans.pop();
    // }

    //printing without popping from orignal stack
    cout<<" \n After reversal \n";
    for(stack<int> dump = ans; !dump.empty(); dump.pop())
    {
        cout<<dump.top()<<" ";
    }

    
    return 0;
}