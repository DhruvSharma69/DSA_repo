#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;
    
    heap()
    {
        
         size = 0; 
        arr[0] = -1;
    }

    void insert(int val)
    {
        
        size = size + 1;
        
        int index = size;
        
        arr[index] = val;
        
        while(index > 1)
        {
                // parent of any node on index i is at index i/2
            
            int par = index/2;
            if(arr[index] > arr[par] )
            { 
                swap(arr[index] , arr[par]);
                index = par;
            }
            else
            return;
        }
         
    }

    // function to print heap 
    void ph()
    {
        // cout<<"printing"<<this<<" ";
        for(int i = 1; i<= size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};


void Heapify(int arr[], int n,int i)
{
    int lar = i;
    int right = 2*i +1;
    int left = 2*i;
    if(left <=n && arr[lar]<arr[left] )
    {
        lar = left;
    }
     if(right <=n && arr[lar]<arr[right] )
    {
        lar = right;
    }
    if(lar!= i)
    {
        swap(arr[lar],arr[i]);
        Heapify(arr,n,i);
    }

    
}

int main()
{
    //object of heap class
    heap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(30);
  //  h1.ph();
    int arr[] = { -1,30,25,46,50};
    for(int i=4; i>=1; i--)
    {
        Heapify(arr,4,i);
    }

    for(int i=1; i<=4; i++)
    {
       cout<<arr[i]<<" ";
    }

     return 0;
    
}