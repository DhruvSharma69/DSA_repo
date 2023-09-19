#include<bits/stdc++.h>
using namespace std;

int findKSmallest(int arr[], int k,int s)
{
    priority_queue<int> q;
    for(int i=0; i<k; i++)
    {
        q.push(arr[i]);
    }
    for(int i=k; i<s; i++)
    {
        if(q.top()> arr[i])
        {
            q.pop();
            q.push(arr[i]);
        }
        
    }

    return q.top();


}
int main()
{

    int arr[] ={7,12,6,4,3,8};            //third smallest is 4
    int size = sizeof(arr)/sizeof(arr[0]);
   int x= findKSmallest(arr,4,size);
   cout<<"kth smallest "<<x;
    return 0;
}