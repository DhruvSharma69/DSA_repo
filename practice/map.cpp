#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int ,int> newmap;
   for(int i=0; i<5; i++)
   {
    newmap[i]=2*i;
   }

    map<int , int> :: iterator it ;
    for(it=newmap.begin();it!=newmap.end();it++)
    cout<<" map first "<<it->first<<" map second "<<it->second<<endl;
   
    return 0;
}