#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    for(int i=0; i<10; i++)
    {
        q.push(i);

    }
    
    queue<int> nq;
    for(int i=0; i<5; i++)
    {
        nq.push(q.front());
        q.pop();
    }

    while(!nq.empty())
    {
        q.push(nq.front());
        nq.pop();
        q.push(q.front());
        q.pop();

    }

    for(int i=0; i<10; i++)
    {
        cout<<q.front();
        q.pop();
    }
    return 0;
}