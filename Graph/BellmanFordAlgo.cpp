#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    map<int, list<int>> adjList;
    map<pair<int, int>, int> weight;
    bool directed;
    graph(bool type) {
        directed = type;
    }

    void addEdge(int v, int u, int w) {
        adjList[v].push_back(u);
        pair<int, int> p = {v, u};
        this->weight[p] = w;
        if (!directed) {
            adjList[u].push_back(v);
            pair<int, int> p = {u, v};
            this->weight[p] = w;
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : adjList[i.first]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
void BF(graph &g, int n, int source)
{
    vector<int> dist(n+1,INT_MAX);
    dist[source] = 0;
    for(int i=1; i<=n; i++)
    {
       for(int k = 1; k<=n; k++)
       {
            for(auto j: g.adjList[k])
            {
                pair<int,int> temp = {k,j};
                if(dist[k] != INT_MAX && dist[k] + g.weight[temp] < dist[j])
                dist[j] = dist[k] + g.weight[temp];
            }
       }
    }

    for(auto i: dist)
    cout<<i<<" ";
}
int main()
{
    graph g1(1);
    //add edges
    g1.addEdge(1,2,2);
    g1.addEdge(1,3,2);
    g1.addEdge(2,3,-1);
   

    int n = 3;
    BF(g1,n,1);
    return 0;
}