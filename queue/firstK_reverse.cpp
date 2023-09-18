#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    int k = 3;
    queue<int> q;
    stack<int> s;

    for(int i=0; i<6; i++)
    q.push(i);

    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for(int i=0; i<k; i++)
    {
        q.push(s.top());
        s.pop();

    }
    for(int i=0; i<q.size()-k ; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    for(int i=0; i<6; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}