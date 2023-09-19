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

    //Deletion funciton
    void deleteHeap()
    {
        if(size == 0)
        return;
        else{
            //swap first with last
            arr[size] = arr[1];

            //reduce size
            size--;
            bool place_found = false;
            int i=1;
            while(place_found != true)
            {
                
                int right = 2*i;
                int left = 2*i +1;
                 if(arr[i] < arr[left] && left < size)
                {
                    swap( arr[i] , arr[left]);
                    
                    i = left;
                }
                else if(arr[i] < arr[right]&& right<size)
                {
                    swap(arr[i] , arr[right]);
                    
                    i = right;
                }
                else{
                    place_found = true;
                    return;
                }
                

            }
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
  void correctPos(int arr[], int i, int s)
    {
        int lar = i;
        int right = 2*i +1;
        int left= 2*i;

        if(left<=s && arr[left] > arr[i])
        lar = left;

        if(right<=s && arr[right] > arr[i])
        lar = right;

        if(lar!=i)
       { 
            swap(arr[i],arr[lar]);
            correctPos(arr,i,s);
       }
    }
    void heapSort(int arr[],int s)
    {
        //swap first no. with last no.
        
        int t = s;
        while(t>s)
        { 
            swap(arr[1],arr[s]);
            correctPos(arr,1,s);
             t--;
        }
        

    }

int main()
{
    int size;
    cout<<"Enter size of heap";
    cin>>size;
    heap h;
    int arr[size];
    
    for(int i=0; i<size;i++)
    {
        
        cin>>arr[i];
    }
    for(int i=0; i<size; i++)
    {
        
        h.insert(arr[i]);
    }
    heapSort(h.arr,size+1);

    for(int i=1; i<=size;i++)
    {
        cout<<h.arr[i]<<" ";
    }
   

   
    return 0;
}