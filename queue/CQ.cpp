#include<iostream>
using namespace std;
//implementation using array
class Q
{
        public:
        int *arrayy;
        int front,rear,size;

        Q(int size)
        {
            this-> size = size;
            arrayy = new int(size);
            front = -1;
            rear = -1;
        }

        // function for enqueue
        void enQ(int element)
        {
            // check for overflow
            if( (rear == size-1 && front == 0 )  || (front == rear + 1))
            {
                cout<<" overflow ";
                return;
            }

            if (front == -1 && rear == -1)
            {
                front++;
                rear++;
                arrayy[rear] = element;
            }

            else if(rear == size -1)
            {
                rear = 0;
                arrayy[rear] = element;
            }

            else 
            {
                rear ++;
                arrayy[rear] = element;
            }

            
        }

        //function for dequeue
        void dQ()
        {
            // check for underflow
            if(front == -1 & rear == -1)
            {
                cout<<" underflow ";
                return ;
            }

            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
             else if(front == size - 1) {
                front = 0;
            }
            else{
                front++;
            }

        }
        
        // FRONT function
        int FRONT()
        {
            int temp = arrayy[front];
            return temp;
        }

        //SIze function

        int SIZE()
        {
            return size;
        }

};

int main()
{
    Q q(5);

     for(int i=0; i<5; i++)
    {
        q.enQ(i*2);
    }

    cout<<"FRONT and SIZE "<<q.FRONT()<<"  "<<q.SIZE()<<endl;
    q.enQ(55);
    for(int i=0; i<3; i++)
    {
        q.dQ();
    }
    q.enQ(55);
    cout<<" front "<<q.FRONT();
    return 0;
}