#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    queue<int> q;
    for(int i=0; i<5; i++)
    q.push(i);

    for(int i=0; i<5; i++)
{s.push(q.front());
q.pop();
}

 for(int i=0; i<5; i++){
    q.push(s.top());
    s.pop();
 }

  for(int i=0; i<5; i++)
   { 
   cout<< q.front();
   cout<<endl;
   q.pop();
   }


    return 0;
}

