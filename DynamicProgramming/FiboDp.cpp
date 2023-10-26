#include<iostream>
using namespace std;

// top down approach
// int utilFib(int n, int arr[])
// {
//     if(n == 0 || n == 1)
//     return n;

//     if(arr[n] != -1)
//     return arr[n];

//     arr[n] = ( utilFib(n-1,arr) + utilFib(n-2,arr) );
//     return  arr[n] ;
// }

// bottom up apprach
int utilFib(int n, int arr[], int i)
{
    if(n == 0 || n == 1)
    return n;

    arr[i] = (arr[i-1] + arr[i-2] );
    if(i == n)
    return arr[i];

    utilFib(n,arr,++i);
}
int Fib(int n)
{
    int arr[n+1];
    for(int i=0; i<=n; i++)
    arr[i] = -1;

    arr[0] = 0;
    arr[1] = 1;
    int ans = utilFib(n,arr,2);
    return ans;
}
 int main()
 {
    int n = 7;
    cout<< Fib(n);
    return 0;
 }