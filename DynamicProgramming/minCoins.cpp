#include<iostream>
using namespace std;

int util(int target, int coins[], int arr[])
{
    if(target < 0)
    return INT_MAX -1;

    if(arr[target] != -1)
    return arr[target];

    int mini = INT_MAX;
    for(int i= 0; i<3; i++)
    {
        int a = util(target - coins[i],coins,arr);
        if(a< mini)
        mini = a;
    }
    arr[target] =  mini + 1;

   // if(arr[target] != -1)
    return arr[target];
   
}
int solve(int target, int coins[])
{
    if(target == 0)
    return 0; 
    int arr[target];
    for(int i=0; i<=target; i++)
        arr[i] = -1;
    arr[0] = 0;
   int ans =  util(target,coins,arr);
   if(ans < INT_MAX)
   return ans;
   else 
   return -1;
}
int main()
{
    int target = 6;
    int coins[] = {2,3,5};
    cout<<solve(target,coins);
    return 0; 
}