#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    for(int i=0; i<5; i++)
    {
        q.push(i*2);
    }

    cout<<"FRONT and SIZE "<<q.front()<<"  "<<q.size()<<endl;

    for(int i=0; i<3; i++)
    {
        q.pop();
    }
    
    cout<<" front "<<q.front();
    return 0;
}