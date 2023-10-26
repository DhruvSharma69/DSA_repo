#include<iostream>
using namespace std;
int util(int rodLength, int arr[], int dp[])
{
    if(rodLength<0)
    return INT_MIN;

    if(dp[rodLength] != -1)
    return dp[rodLength];

    int maxi = INT_MIN;
    for(int i=0; i<3; i++)
    {
        int ans = 1 + util(rodLength - arr[i], arr, dp);
        if(ans > maxi)
        maxi = ans;
    }
    dp[rodLength] = maxi;

    return dp[rodLength];
}
int solve(int rodLength, int arr[])
{

    if(rodLength == 0)
    return 0;
    int dp[rodLength+1];
    for(int i=0; i<=rodLength; i++)
    dp[i] = -1;

    dp[0] = 0;
    int ans = util(rodLength,arr,dp);

    if(ans == INT_MIN)
    return -1;

    return ans;
}
int main()
{
    int rodLength = 7;
    int seg[] = {2,4,5};
    cout<<solve(rodLength,seg);
    return 0;
}