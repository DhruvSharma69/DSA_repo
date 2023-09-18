#include<iostream>
using namespace std;

class GetMin_stack
{
    public:
    int *arr;
    int top,size;
    int min = INT_MAX;

    GetMin_stack(int size)
    {
        this->size = size;
        arr = new int(size);
        top = -1;
    }
    void push(int element)
    {
        if(top == size-1)
        {
            cout<<"stack overflow "<<endl;
            return ;
        }

        if(element > min  || top == -1)
        {
            top = top+1;
            arr[top] = element;  
        }
        else{
            int val = 2*element - min;
            min = element;
            top = top+1;
            arr[top] = val;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"underflow"<<endl;
            return;
        }

        if(arr[top] > min)
        {
            top = top-1;
            
        }
        else{
            int val = 2*min - arr[top];
            min = val;
            top = top-1;
        }
    }
};

int main()
{
    GetMin_stack obj(5);
    for(int i=0; i<5; i++)
    obj.push(5-i);

    cout<<obj.min;

    for(int i=0; i<3; i++)
    obj.pop();

    cout<<"\n"<<obj.min;


    return 0;
}