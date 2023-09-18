#include<iostream>
#include<Stack>
using namespace std;

void CorrectPlace(stack <int> &s, int out)
{
     int temp ;
    if(s.empty())
    {
        s.push(out);
        return;
    }
   else if(s.top() > out)
    {
         temp = s.top();
        s.pop();
        CorrectPlace(s,out);
        s.push(temp);
        return;
    }
    else{
        s.push(out);
        
        return;
    }


}

void SortStack(stack <int> &s)
{
    if(s.empty())
    return;

    int out = s.top();
    s.pop();
    SortStack(s);
    CorrectPlace(s,out);
    
    return;
}

int main()
{
    stack <int> s;
    cout<<" Enter the size of the stack \n";
    int size;
    cin>>size;
    for(int i=1; i<=size; i++)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }

    SortStack(s);

    for(stack <int> dump = s; !dump.empty(); dump.pop())
    {
        cout<<dump.top()<<" ";
    }

    return 0;
}
