#include<iostream>
using namespace std;
class NQ{
    private:
    int n,size;
    int freespace,at;
    int *next, *front, *rear, *arr;


    public:
//constructor

    NQ(int n,int size )
    {
        this ->n = n;
        this ->size = size;
        
        arr = new int(size);
        next = new int(size);
        front = new int(n);
        rear = new int(n);

        freespace = 0;

        for(int i=0; i<size-1; i++)
        next[i] = i+1;

        next[size-1] = -1;

        for(int i=0; i<n;i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
      
        
    }
    // push func
    void Npush(int e, int k) //push element e in queue k
    {
        //check overflow
        if(freespace == -1)
       { cout<<"overflow";
        return;
        }

        // if pushing first element of k queue
        if(front[k] == -1)
        {
            at = freespace;
            arr[at] = e;          // e inserted into (at) index of arr
            freespace = next[freespace];  //freespace updated to point to next freespace
            front[k] = at;
           // next[at] = rear[k]; 
            rear[k] = at;

        }
        else{
             at = freespace;
            arr[at] = e;          // e inserted into (at) index of arr
            freespace = next[freespace];  //freespace updated to point to next freespace
            next[rear[k]] = at; 
            rear[k] = at;
        }



    }

    void Npop(int k)
    {
        //check underflow
        if(rear[k] == -1)
        {
            cout<<"underflow";
            return;

        }
        else if(front[k] == rear[k]){
            at = front[k];
           // rear[k] = next[at];
           next[at] = freespace;

           freespace = at;
           rear[k]=-1;
           front[k]=-1;
            
        }
        else{
            at = front[k];
            front[k] = next[at];

           next[at] = freespace;

           freespace = at;
        }
    }

    int showF(int k)
    {
        return front[k];
    }
    int showR(int k)
    {
        return rear[k];
    }
};

int main()
{
    NQ q(3,10);
    cout<<" FIrst see front and rear of 0th q \n";
  cout<<  q.showF(0);
   cout<<  q.showR(0);
    cout<<" now push and then see front and rear \n";
    q.Npush(1,0);
     cout<< q.showF(0);
   cout<<  q.showR(0);
    cout<<" now push and then see front and rear \n";
    q.Npush(2,0);
    cout<<  q.showF(0);
    cout<< q.showR(0);
    cout<<" now push and then see front and rear \n";
    q.Npush(3,0);
    cout<<  q.showF(0);
   cout<<  q.showR(0);
   cout<<" \n now push in 2nd and third q \n";
    q.Npush(100,1);
     q.Npush(300,2);
      q.Npush(30,1);

      cout<<" now see front and rear of 0,1,2 \n";
      cout<<q.showF(0)<<q.showR(0)<<endl;
      cout<<q.showF(1)<<q.showR(1)<<endl;
      cout<<q.showF(2)<<q.showR(2)<<endl;

cout<<" \n now pop from 3 twice \n";
q.Npop(2);
q.Npop(2);
cout<<q.showF(2)<<q.showR(2)<<endl;

cout<<" \n now pop from 1 twice \n";
q.Npop(0);
q.Npop(0);
cout<<q.showF(0)<<q.showR(0)<<endl;

return 0;
}