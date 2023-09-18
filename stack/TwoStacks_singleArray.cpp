#include<iostream>
using namespace std;

class twoStacks
{
    private:
    int *arr;
    int size;
    int TOP1 = -1, TOP2 = size;

    public:
    twoStacks(int size)
    {
        this->size = size;
        arr = new int(size);
    }
    void push1(int data)
    {
        TOP1++;
        if(TOP1 == TOP2)
        {
            cout<<" No space for pushing in stack 1 \n";
            TOP1--;
            return;
        }
        arr[TOP1] = data;
    }

    void push2(int data)
    {
        TOP2--;
        if(TOP2 == TOP1)
        {
            cout<<" No space for pushing in stack 2 \n";
            TOP2++;
            return;
        }
        arr[TOP2] = data;
    }

    void pop1()
    {
        if(TOP1 == -1)
        {
            cout<<" stack 1 is already empty \n";
            return;
        }
        TOP1--;

    }

    void pop2()
    {
        if(TOP2 == size)
        {
            cout<<" stack 2 is already empty \n";
            return;
        }
        TOP2--;

    }

    void Show_full_stack1()
    {
        for(int i=0; i<= TOP1;i++)
        cout<<"  "<<arr[i];
    }

    void Show_full_stack2()
    {
        for(int i=size-1; i>= TOP2; i--)
        cout<<"  "<<arr[i];
    }

    int top1()
    {
        return arr[TOP1];
    }

    int top2()
    {
        return arr[TOP2];
    }
    
};

int main()
{
    cout<<"\nhello \n";
    twoStacks s(10);
cout<<"\nhello \n";
    for(int i=0,j=9; i<=5,j>6; i++,j--)
    {
        cout<<"\nhello \n"<<i<<j;
        s.push1(i);
        s.push2(j);
    }
cout<<"\nhello \n";
    cout<<"\nDisplaying TOPS \n";
    cout<<s.top1()<<"  "<<s.top2();
    cout<<"\nNow exceeding limit of s1 then s2 \n";
    s.push1(100);
    s.push2(100);
    cout<<"\n POPPing from both stacks\n";
    s.pop1();
    s.pop2();
     cout<<"\nDisplaying TOPS \n";
    cout<<s.top1()<<"  "<<s.top2();
    return 0;
}