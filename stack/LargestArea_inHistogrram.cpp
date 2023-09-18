#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/* ******************************** BRUTE FORCE APPROACH ************************************


int maxx(vector<int> v)                    // TO FIND THE MAX ELEMENT IN VECTOR 
{
    int n = v[0];
    for(int i=0;i<v.size(); i++)
    {
        if(v[i+1]>n)
        n = v[i+1];
    }
    return n;
}

int countright(vector<int> v,int i)         // TO COUNT HOW MANY RECTANGLES ARE BIGGER THAN CURRENT RECTAGLE SO TO EXTEND THE AREA TO RIGHT 
{
    if(i== v.size()-1)
    return 0;
    int j = i+1;
    int  count=0;
    while(j <= v.size()-1)
    {
 //       cout<<"\n inside while ";
        if(v[i]>v[j])
        {
 //           cout<<" \n inside if break for i,j "<<i<<" "<<j;
            break;
        }
        count++;
 //       cout<<"\n count for i , j "<<count<< " "<<i<<" "<<j<<" \n";
        j++;
    }
    return count;
}

int countleft(vector<int> v,int i)      // TO COUNT HOW MANY RECTANGLES ARE BIGGER THAN CURRENT RECTAGLE SO TO EXTEND THE AREA TO LEFT 
{
      if(i==0)
    return 0;
    int j = i-1, count=0;
    while(j >= 0)
    {
        if(v[i]>v[j])
        break;
        count++;
        j--;
    }
    return count;
    
}

int maxArea(vector<int> v)          // FUNCTION TO FIND ANSWER 
{
    vector<int> allarea;
    for(int i=0; i<v.size();i++)
    {
        int c1 = countright(v,i);
        int c2 = countleft(v,i);
        int count = c1 + c2 + 1;
       
        int area = count*v[i];              //AREA = L x B
  //       cout<<" \n for i = "<<i<<" c1 , c2 , count , area are "<<c1<<" "<<c2<<" "<<count<<" "<< area<<" \n";
        allarea.push_back(area);
    }
  //  cout<<"\n all area: ";
  //  for(int i=0;i<allarea.size();i++)
  //  cout<<" "<<allarea[i];



    int max1 = maxx(v);
  //  cout<<" \n max 1 "<<max1;
    int max2 = maxx(allarea);
   // cout<<" \n max 2 "<<max2;
   
    if(max1>max2)
    return max1;
    else
    return max2;

}

int main()
{
    vector <int> v = {4,2,3,1};
  //  cout<<v.size();
    cout<<maxArea(v);
    return 0;
}
*/

// ******************************* BETTER APPORACH USING STACK***********************

int maxx(vector<int> v)                    // TO FIND THE MAX ELEMENT IN VECTOR 
{
    int n = v[0];
    for(int i=0;i<v.size(); i++)
    {
        if(v[i+1]>n)
        n = v[i+1];
    }
    return n;
}


vector <int> giveArrRight(vector<int> v)
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
vector <int> giveArrLeft(vector<int> v)
{
    vector <int> ans = v;
    stack <int> s;
    s.push(-1);
     for(int i = 0; i<v.size(); i++)
     {
         while(s.top() != -1 && v[s.top()]> v[i])
            s.pop();
            ans[i] = s.top();
            s.push(i);
     }
return ans;
    
}

int maxArea(vector<int> v)
{
    int size = v.size();
    vector <int> next = giveArrRight(v);
    vector <int> prev = giveArrLeft(v) ;
    vector <int> ans;

    for(int i=0;i<size;i++)
    {
        int l = v[i];
         if(next[i]==-1)
         next[i]==v.size();
        int b = next[i] - prev[i] -1 ;
        int area = l * b;
        ans.push_back(area);
    }
    int k = maxx(ans);
    return k;
}


   int main()
{
    vector <int> v = {4,2,3,1};
    int show = maxArea(v);
    cout<<" max area in histogram is "<<show;
    return 0;
}
