#include<iostream>
#include<stack>
using namespace std;

bool Check_Brackets(string s1)
{
    int size = s1.length();
    cout<<" size is "<<size<<endl;
    stack <int> s;
    
    for(int i=0; i<size;i++)
    {
        bool check = true;
        if(s1[i]=='(' ||  s1[i]== '+' || s1[i]=='-' || s1[i]=='*' || s1[i]=='/')
        {
            s.push(s1[i]);
        }
        else if(s1[i]==')'){
            while(s.top() != '(')
            {
                if(s.top()== '+' || s.top()=='-' || s.top()=='*' || s.top()=='/' )
                {
                    check = false;
                    
                
                }
                s.pop();
            }
            if(check == true)
            return true;
            s.pop();
        }
    }
    return false;
}

int main()
{
    string s1 = " (( ( a + b ) * C ) )";

    bool ans = Check_Brackets(s1);
    cout<<ans;
    return 0;
}