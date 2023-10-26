#include<iostream>
using namespace std;
int solveu(int n, int dp[])
{
    if(n == 1)
    return 0;

    if(n== 2)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    int ans = (n-1)* (solveu(n-1,dp) + solveu(n-2,dp));
    dp[n] =  ans;
    return dp[n];
}
int solve(int n)
{
    int dp[n+1];
    for(int i=0; i<=n; i++)
    dp[i] = -1;
    dp[1] = 0;
    dp[2] = 1;

    return solveu(n,dp);
}
int main()
{
    int n= 5;
    cout<<solve(n);
    return 0;
}