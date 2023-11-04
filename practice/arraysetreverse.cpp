#include<iostream>
using namespace std;
void parr(int arr[])
{
    for(int i=0;i<12;i++)
    cout<<arr[i]<<" ";
}

void answer(int arr[], int k)
{
    int temp=0;
    while(temp<=12)
    {

    
    int i=temp,j=i+k-1;
    while(j>i)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
        
    }
    temp=temp+k;
    }
    parr(arr);
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int k;
    cin>>k;
    answer(arr,k);
    //parr(arr);
    return 0;
}