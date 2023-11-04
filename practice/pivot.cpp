#include<iostream>
using namespace std;
void findpivot(int arr[],int size)
{
    int k=0;
    
    while(k<size)
    {
        int sum1=0,sum2=0;
        for(int i=0;i<size;i++)
        {
            if(i<k)
            sum1+=arr[i];
            else if(i>k)
            sum2+=arr[i];
        }
        if(sum1==sum2)
        cout<<" pivot is "<<arr[k];
        k++;
    }
}

int main()
{
    int arr[]={1,2,5,4,6,2};
    int size= sizeof(arr)/sizeof(int);
    
    findpivot(arr,size);
    return 0;
}