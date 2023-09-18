#include<iostream>
#include<stack>
using namespace std;
bool valid_brackets(string s)
{
    int size = s.length();
    
    stack <char> t;
    int p = 0;
    while(p<size)
    {
        if(t.size() == 0 && ((s[p] == ']'  ) || ( s[p] == ')' ) || ( s[p] == '}' ) ))
        {
            return false;
        }
        
        if(s[p] == '[' || s[p] == '(' || s[p] == '{')
        {
            t.push(s[p]);

        }
        else
        {
           
            if( (s[p] == ']' && t.top() == '['  ) || ( s[p] == ')' && t.top() == '(' ) || ( s[p] == '}' && t.top() == '{'))
            {
                
                t.pop();
            }
            else
            return false;
        }
        p++;
    }
    if(t.empty())
    return true;
    else
    return false;
}

int main()
{
    string s;
    for(int i=0;i<1;i++)//  
    {
        char a;
        cin>>a;
        s.push_back(a);
    }

    bool ans = valid_brackets(s);
    cout<<ans;
    return 0;

}