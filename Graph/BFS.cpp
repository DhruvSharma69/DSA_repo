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

void BFS(graph g)
{
    map<int, bool> visited;
    for (const auto &entry : g.adjList) {
        visited[entry.first] = false;
    }

    queue<int> q;
    for (const auto &entry : g.adjList) {
        int source = entry.first;
        if (!visited[source]) {
            q.push(source);
            visited[source] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                cout << current << " ";

                for (const auto &neighbor : g.adjList[current]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    graph g1(1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(2,5);
    g1.addEdge(1,3);
    g1.addEdge(5,3);
    g1.addEdge(4,6);
    g1.addEdge(4,7);

    g1.printAdjList();
    BFS(g1);
    return 0;
}