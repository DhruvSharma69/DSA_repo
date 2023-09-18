#include<iostream>
#include<vector>
#include<Stack>
using namespace std;
// int findindex(int x,vector<int> v)
// {
//     for(int i=v.size()-1; i>=0; i--)
//     {
//         if(x == -1)
//         return -1;
//        else if(v[i] == x)
//         return i;
//     }
//     return -1;
// }
// vector<int> callright(vector<int> v)
// {
//     vector<int> ans = v;
//     stack<int> s;
//     s.push(-1);
//     for(int i=v.size()-1; i>=0;i--)
//     {
//         while(s.top()>v[i])
//         {
//             s.pop();
//         }
//         int index = findindex(s.top(),v);
//         s.push(v[i]);
//         ans[i] = index;
//     }
//     return ans;
// }

vector <int> callright(vector<int> v)
{
    vector <int> ans = v;
    stack <int> s;
    s.push(-1);
     for(int i = v.size()-1; i>=0; i--)
     {
         while(s.top() != -1 && v[s.top()]>= v[i])
            s.pop();
            ans[i] = s.top();
            s.push(i);
     }
return ans;
}

int main()
{
    vector <int> v = {4,5,3,6,1};
    vector <int> ans = callright(v);
    for(int i=0; i<ans.size(); i++)
    cout<<" "<<ans[i];
    return 0;

}