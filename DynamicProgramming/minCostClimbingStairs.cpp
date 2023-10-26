#include<bits/stdc++.h>
using namespace std;
int util(int n, int cost[], int arr[])
{
    if(n == 0 || n == 1)
    return cost[n];

    if(arr[n] != -1)
    return arr[n];

    arr[n] = min(util(n-1, cost, arr), util(n-2, cost, arr)) + cost[n];
    return arr[n];
}
int util2(int n, int cost[])
{
    if(n == 0 || n == 1)
    return cost[n];

     int p2 = cost[0];
     int p1 = cost[1];
    for(int i=2; i<n; i++)
    {
        int temp  = p1;
        p1 = min(p1, p2) + cost[i];
        p2 = temp;
    }
    return min(p1,p2);
}
int getCost(int n, int cost[])
{
    int arr[n+1];
    for(int i=0; i<=n; i++)
    arr[i] = -1;

   // int ans = min(util(n-1, cost, arr), util(n-2, cost, arr));
   int ans = util2(n, cost);
    return ans;
}
int main()
{
    int n = 3;
    int cost[] = {10,15,20};
    cout<<getCost(n,cost);
    return 0;
}