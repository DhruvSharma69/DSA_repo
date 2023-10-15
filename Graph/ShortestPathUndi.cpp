#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    map<int,list<int>> adjList;
    bool directed;
    graph(bool type)
    {
        directed = type;
    }
   void addEdge(int v, int u)//an edge that joins v to u if directed = 1 and also join u to v if d = 0 
    {
        adjList[v].push_back(u);
        if(directed == 0)
        adjList[u].push_back(v);
    }

    void printAdjList()
    {
        for(auto i: adjList)
        {
            cout<<i.first<<" -> ";
            for(auto j: adjList[i.first])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

void shortestPath(graph g, int s, int d)
{
    map<int,bool> visited;
    map<int,int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
     visited[s] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
       

        for(auto i: g.adjList[front])
        {
            if(visited[i] != true)
            {
                 visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
        }

    }

    // parents map has been created
    int temp = d;
    stack<int> st;
    while(temp != s)
    {
        st.push(temp);
        temp = parent[temp];

    }
    st.push(temp);

    // print shortest path
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    graph g1(0);
    g1.addEdge(1,2);
    g1.addEdge(1,4);
    g1.addEdge(1,3);
    g1.addEdge(2,5);
    g1.addEdge(5,8);
    g1.addEdge(3,8);
    g1.addEdge(4,6);
    g1.addEdge(6,7);
    g1.addEdge(7,8);
    


    shortestPath(g1,6,8);
    return 0;
}