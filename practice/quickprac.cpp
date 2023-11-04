#include<iostream>
using namespace std;
void input(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cin>>arr[i];
}

void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}
void partition(int arr[],int size,int newarr[],int count,int key)
{
    int i=0,j=count;
    while(i!=count&&j!=size)
    {
        if(arr[i]<newarr[count-1]&& i!=key)
        {
            
            newarr[i]=arr[i];
        }
        else
        {
            if(arr[j]>newarr[count-1])
            {
                
                newarr[j]=arr[j];
            }
            else
            {
                swap(arr[i],arr[j]);
                newarr[i]=arr[i];
                newarr[j]=arr[j];
            }
        }
        i++;
        j++;
    }
}
void RightPlace(int arr[],int size,int key,int newarr[])
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]<=arr[key])
        count++;
    }
    //right index for key is count
    //now  partition 
    newarr[count-1]=arr[key];
    partition(arr,5,newarr,count,key);

    
}
void quickSort(int arr[],int size)
{
    

}
int main()
{
    int arr[5];
    input(arr,5);
    quickSort(arr,5);
    print(arr,5);
    return 0;
}