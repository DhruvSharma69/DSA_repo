#include<iostream>
using namespace std;
int util(int nums[], int n, int i, int arr[])
{
   
    if(i<n)
    {
        if(arr[i] != -1 )
        return arr[i];
        int inc = nums[i] + util(nums,n,i+2,arr);
        int exc = util(nums,n,i+1,arr);
        arr[i] = max(inc,exc);
    }
    else
    return 0;
}
int solve(int nums[], int n)
{
    if(n == 0)
    return -1;

    if(n == 1)
    return nums[1];

    int arr[n+1];
    for(int i=0; i<=n; i++)
    arr[i] = -1;

    int ans = util(nums,n,0,arr);
    return ans;
}
int main()
{
    int nums[] = {7,5,3,8,4};
    int n = 5;
    cout<<solve(nums,n);
}