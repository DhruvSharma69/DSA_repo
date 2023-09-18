#include<iostream>
using namespace std;

class Stack
{
    private:
    //data members
    int size;
    int *arrS;
    int TOP = -1;

    public:
    //member functions
    Stack(int size)
    {
        this->size = size;
         arrS = new int(size);
    }

    void push(int data)
    {
        TOP++;
        if(TOP > size )
        {
            cout<<" Already full \n";
            TOP--;
            return ;
        }
        arrS[TOP] = data;
    }

    void pop()
    {
        if(TOP == -1)
        {
           cout<<" Already empty ";
           return ;
        }
        TOP--;

    }

    void peek()
    {
        cout<<arrS[TOP];
    }

    void ShowFullStack()
    {
        for(int i=0; i<=TOP; i++)
        cout<<"  "<<arrS[i];
    }

    int top()
    {
        return arrS[TOP];
    }

};

int main()
{
    Stack s(10);
    
    for(int i=0;i<10;i++)
    s.push(i);


    cout<<"Peek \n";
    s.peek();


    cout<<" \n ShowFullStack \n";
    s.ShowFullStack();


    cout<<"\n POP \n";
    s.pop();


    cout<<" returning top \n";
    cout<<s.top();

    cout<<" exceeding limit \n";
    

    return 0;
}