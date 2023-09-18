//given an array of positive numbers, you have to replace each element of array with next smaller element 
//you find while moving towards end, if no smaller element is found, replace with -1.
//example given array 2 3 1 6 4 
//replace 2 with next smaller element you find while moving right
//it becomes 1 3 1 6 4 
// do same for 3 
//1 1 1 6 4 
// same for 1, but 1 doesent have anything smaller so replace with -1
// 1 1 -1 6 4
//repeat for 6
//1 1 -1 4 4 
//now for last element there is nothing on right so replace with -1

#include<iostream>
#include<stack>
using namespace std;

int * solve(int arr[])
{
    int size = 5;
    static int ans[5];
    stack<int> s;
    s.push(-1);
    for(int i=size-1; i>=0; i--)
    {
        // if(s.top()<arr[i])
        // {
        //     ans[i] = s.top();
        //     s.push(arr[i]);
            
        // }
        // else{
            while(s.top()>arr[i])
            s.pop();
            ans[i] = s.top();
            s.push(arr[i]);
        //}
    }
    return ans;
}
int main()
{
    int arr[] = {3,5,2,4,6};
     int size = 5;
    int *ans = solve(arr);
    for(int i=0;i<size;i++)
    {
        cout<< *(ans+i)<<" ";
    }
    return 0;
}