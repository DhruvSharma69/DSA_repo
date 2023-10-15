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
void SortDfs(graph &g, map<int, bool> &visited, stack<int> &ans, int vertex)
{
    visited[vertex] = true;
    for(auto i: g.adjList[vertex])
    {
        if(visited[i] != true)
        {
            SortDfs(g,visited,ans,i);
            
        }
    }
    ans.push(vertex);
    // visited[vertex] = false;
}

//**************************Sort using DFS*************************
void TopSort(graph &g){
    map<int, bool> visited;
    stack<int> ans;
    for(int i=1; i<=6; i++)
    {
        if(!visited[i])
        {
            SortDfs(g,visited,ans,i);
            
        }
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

//***********************Sort using BFS or Kahn's Algo*****************************

void KahnAlgo(graph &g)
{
    vector<int> indegree(6,0);
    // for(int i=0; i<6; i++)
    // indegree[i] = 0;

    for(auto i: g.adjList)
    {
        for(auto j: g.adjList[i.first])
        {
            indegree[j-1]++;
        }
    }

    queue<int> q;
    for(int i=0; i<6; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i+1);
        }
    }

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        cout<<front<<" ";
        for(auto i: g.adjList[front])
        {
            indegree[i-1]--;
            if(indegree[i-1] == 0)
            q.push(i);

        }
    }
}
int main()
{
    graph g1(1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(3,4);
    g1.addEdge(2,4);
    g1.addEdge(4,5);
    g1.addEdge(4,6);
    g1.addEdge(5,6);

    TopSort(g1);
    cout<<endl;

    KahnAlgo(g1);
    return 0;

}