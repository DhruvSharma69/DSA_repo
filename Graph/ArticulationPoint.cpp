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
void util(graph g, vector<bool> &visited, vector<int> &parent, vector<int> &minDis, vector<int> &firstTouch, int vertex, int &timer) {
    visited[vertex] = true;
    minDis[vertex] = timer;
    firstTouch[vertex] = timer;
    timer++;
    int child = 0;
    for (auto i : g.adjList[vertex]) {
        if (i == parent[vertex] && parent[vertex] != -1) // Correct the condition
            continue;

        if (!visited[i]) {
            parent[i] = vertex;
            util(g, visited, parent, minDis, firstTouch, i, timer);
            minDis[vertex] = min(minDis[vertex], minDis[i]);

            // Check for a bridge.
            if (minDis[i] > firstTouch[vertex] && parent[vertex] != -1) {
                cout << vertex << endl; 
            }
            child ++;
        } else {
            minDis[vertex] = min(minDis[vertex], firstTouch[i]);
        }
    }
    if(parent[vertex] == -1 && child > 1)
    cout << vertex << endl;
}

void GetPoints(graph &g1, int n)
{
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    vector<int> minDis(n, -1); // Initialize with INT_MAX
    vector<int> firstTouch(n, -1); // Initialize with INT_MAX
    int timer = 0;
    for(int v=0; v<n; v++)
    { 
        if(visited[v] != true)
        util(g1, visited, parent,  minDis, firstTouch,v,timer);
    }
}
int main()
{
    graph g1(0);
    //add edges
    g1.addEdge(1,0,0);
    g1.addEdge(2,0,0);
    g1.addEdge(1,2,0);
    g1.addEdge(3,4,0);
    g1.addEdge(3,5,0);
    g1.addEdge(5,4,0);
    g1.addEdge(0,4,0);


    int n = 6;
    GetPoints(g1,n);
    return 0;
}