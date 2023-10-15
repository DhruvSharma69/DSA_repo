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
// ********************The code below is for Undirected graph***************************
/*
bool util(graph &g, map<int,bool> &visited,queue<int> &q, map<int,int> &parent)
{
    while(!q.empty())
   { 
        int vertex = q.front() ;
        visited [vertex] = true;
        q.pop();
        for(auto i: g.adjList[vertex])
        {
            if(visited[i] == false)
            {
                q.push(i);
                parent[i] = vertex;
               visited[i] = true;
            }
            else if(visited[i] == true && i != parent[vertex] )
            return true;

        }
    }
    return false;
}
bool checkCycle(graph g)
{
    map<int,bool> visited;
    queue<int> q;
    map<int,int> parent;
    for(auto i: g.adjList)
    {
        int vertex = i.first;
        if(!visited[vertex])
       { 
        q.push(vertex);
        bool ans = util(g,visited,q,parent);
        if(ans == true)
        return true;
        }
    }
    return false;
}
*/

// ***************************the code below is for directred graph**********************

bool utilDirected(graph g, map<int,bool> &visited, map<int,bool> &dfscall, int vertex)
{
    visited[vertex] = true;
    dfscall[vertex] = true;
    for(auto i: g.adjList[vertex])
    {
        if(!visited[i])
        {
            bool ans = utilDirected(g, visited, dfscall, i);
            if(ans)
                return ans;
        }
        else if(dfscall[i])
            return true;
    }
    dfscall[vertex] = false;
    return false;
}

bool checkCycleDirected(graph g)
{
    map<int,bool> visited;
    map<int,bool> dfscall;
    for(auto i: g.adjList)
    {
        int vertex = i.first;
        if(!visited[vertex])
        {
            bool ans = utilDirected(g, visited, dfscall, vertex);
            if(ans)
                return ans;
        }
    }
    return false;
}
int main() {
    // Create a graph with undirected edges
    graph g1(1);

    // Add edges to the first component
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(1, 3);

    // Print the adjacency list of the first component
    cout << "Component 1:" << endl;
    g1.printAdjList();

    // Check for cycles in the first component
    bool ans1 = checkCycleDirected(g1);

    if (ans1) {
        cout << "Component 1 contains cycles." << endl;
    } else {
        cout << "Component 1 does not contain any cycles." << endl;
    }

    // Create another graph for the disconnected component
    graph g2(0);

    // Add edges to the second component
    g2.addEdge(4, 5);
    g2.addEdge(6, 7);

    // Print the adjacency list of the second component
    cout << "Component 2:" << endl;
    g2.printAdjList();

    // Check for cycles in the second component
    bool ans2 = checkCycleDirected(g2);

    if (ans2) {
        cout << "Component 2 contains cycles." << endl;
    } else {
        cout << "Component 2 does not contain any cycles." << endl;
    }

    return 0;
}
