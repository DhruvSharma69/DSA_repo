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


/*void heapSort(int arr[], int size)
{
    if(size<=1)
    return;

    while(size>1)
    {
        //first swap root and end
        swap(arr[0],arr[size-1]);
        //reduce the size of arr
        size--;
        //put root in right place
        if(arr[0] < )

        
        
    }
}*/

int main()
{
    int size;
    cout<<"Enter size of heap";
    cin>>size;
    heap h;
    for(int i=0; i<size; i++)
    {
        int val;
        cin>>val;
        h.insert(val);
    }

    for(int i=0; i<size+1; i++)
    {
        cout<<h.arr[i]<<" ";
    }

    h.deleteHeap();
    for(int i=0; i<size-1; i++)
    {
        cout<<h.arr[i]<<" ";
    }
   
    return 0;
}