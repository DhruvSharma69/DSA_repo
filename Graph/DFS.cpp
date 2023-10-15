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
void dfs(int vertex, map<int, bool> &visited, graph &g) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : g.adjList[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, g);
        }
    }
}

void DFS(graph g) {
    map<int, bool> visited;

    for (auto pair : g.adjList) {
        int vertex = pair.first;
        if (!visited[vertex]) {
            dfs(vertex, visited, g);
        }
    }
}

int main()
{
     graph g1(0);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(2,5);
    g1.addEdge(1,3);
    g1.addEdge(5,3);
    g1.addEdge(4,6);
    g1.addEdge(4,7);

    g1.printAdjList();
    DFS(g1);
    return 0;
}