#include<iostream>

using namespace std;

/* *********************************** NON OPTIMIZED SOLn**************************
class Nstack
{
    public:
    
    int size;               // size of array
   int* arr;
    int N, data;            // number of stacks, data to push in stacks
    int* TOP;
    

                   
    Nstack(int size, int N)
    {
        this->N = N;
        this->size = size;
        arr = new int(size);
         TOP = new int(N);
        for(int i=0; i<N; i++)
        TOP[i] = -1;

    }
    void PUSH(int data, int k)  // push data in k th stack
    {
        int sizeS = size/N;    //size of a stack
        this->data = data;
          
          

        // check if k th stack is full
        
        if(TOP[k-1] == sizeS*k-1)
        {cout<<" stack "<<k<<" is already full ";
        return;}

        else if(TOP[k-1] == -1 )
        {
            TOP[k-1] = (sizeS)*(k-1);
            arr[TOP[k-1]] = data;
            
            
        }
        else{
            TOP[k-1]++;
            arr[TOP[k-1]] = data;
            
        }     

    }

    void PRINT_COMPLETE()
    {
        for(int i=0; i<20; i++)
        cout<<" "<<arr[i]<<endl;
        
    }
    
};

int main()
{
    Nstack obj(20,4);
    obj.PUSH(11,1);
    obj.PUSH(11,1);
    obj.PUSH(11,1);
    obj.PUSH(11,1);
    obj.PUSH(11,1);

    obj.PUSH(22,2);
    obj.PUSH(22,2);
    obj.PUSH(22,2);
    obj.PUSH(22,2);
    obj.PUSH(22,2);
  

    obj.PUSH(33,3);
    obj.PUSH(33,3);
    obj.PUSH(33,3);
    obj.PUSH(33,3);
    obj.PUSH(33,3);
    
    obj.PUSH(44,4);
    obj.PUSH(44,4);
    obj.PUSH(44,4);
    obj.PUSH(44,4);
    obj.PUSH(44,4);
   obj.PRINT_COMPLETE();
   obj.PUSH(3,2);

    
    return 0;

}
*/

// ********************** OPTMIZED SOLn ******************************
class Nstacks{
    private:
    int data, size, k;
    int * top;
    int * arr;
    int * next;
    int free_space;

    
    Nstacks(int size, int k)  // size of array and k no. of stacks
    {
        this->size = size;
        this->k = k;
        arr = new int(size);


        // 'next' array will store 2 things -> next free spaces availabel in arr, ->previous element of element stored in arr
        next = new int(size);
        // initialse next array according to next empty space available in arr 
        for(int i=0; i< size - 1; i++)
        next[i] = i+1;
        next[size-1] = -1;      // for the last element in arr there is no further empty space available


        top = new int(k);
        // initialise all top elements by -1
        for(int i=0;i<k;i++)
        top[i] = -1;

        
        // show where is next free space in 'next' array
         free_space = 0;


    }

    
// push operation funcion ..... it will take two parameters what element to push and in which stack to push

void  PUSH(int element, int w) //element to pushed in wth stack
{
    //CHECK stack overflow condition
    if(free_space == -1)
    {
        cout<<" stack overflow "<<endl;
        return;
    }

    // first step is to input the value in orignal arr
    arr[free_space] = element;

       // now update free_space to show next free space for other element
    int index = free_space;
    free_space = next[free_space];

    // now update next array to show prev value before element was inserted
    
    next[index] = top[w];

// update the top array 

    top[w] = index;
  
}

// function to pop from wth stack
void pop(int w)
{
    //if stack is already empty
    if(top[w]== -1){
    cout<<"stack already empty "<<endl;
    return;}

    else
    {
        int curr = top[w];          // curr pointing to index of current top element of stack w
        cout<<arr[curr]<<endl;   // printing the popped element
    top[w] = next[curr];            // after popping top will change to prev element staored in stack w which is shown by next array
    next[curr] = free_space;        // since the element is popped there is freespace available 
    free_space = curr;          //first nex[curr] which is space which was just emptitied will have current freespace available
                                // and then free_space pointer which stored element at index will store curr becz that place is emptitied
    
    }
}

};
