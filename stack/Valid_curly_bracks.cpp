#include<iostream>
#include<Stack>
using namespace std;
bool isvalid(string s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '{')
        st.push(s[i]);

        else{
            if(st.empty())
            return false;

            else
            st.pop();
        }
    }
    if(st.empty())
    return true;

    return false;
}
int main()
{
    string s = "{{}}{}}{";
    cout << isvalid(s);
    return 0;
}