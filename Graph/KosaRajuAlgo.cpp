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
void utilTopo(graph g, vector<bool> &visited,stack<int> &st, int vertex) {
    visited[vertex] = true;
    
    for (auto i : g.adjList[vertex]) {
        if (!visited[i]) {
            utilTopo(g, visited,st,i);
           
            }
        } 
        st.push(vertex);
}
        
void util(vector<bool> &visited, map<int,list<int>> &tr, int vertex)
{
    visited[vertex] = true;
    for(auto i: tr[vertex])
    {
        if(visited[i] == false)
        util(visited,tr,i);
    }
}
void getCompo(graph &g1, int n)
{
    vector<bool> visited(n,false);
    stack<int> st;
    for(int v=0; v<n; v++)
    { 
        if(visited[v] != true)
        utilTopo(g1, visited, st, v);
    }

    map<int,list<int>> transpose;
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
        for(auto k: g1.adjList[i])
        {
            transpose[k].push_back(i);
        }
    }

    int count = 0;
    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        if(visited[t] == false)
        {util(visited,transpose,t);
        count++;}
    }

    cout<<count;
}
int main()
{
    graph g1(1);
    //add edges
    g1.addEdge(1,2,0);
    g1.addEdge(2,0,0);
    g1.addEdge(0,1,0);
    g1.addEdge(3,4,0);
    g1.addEdge(4,5,0);
    g1.addEdge(5,3,0);
    g1.addEdge(0,4,0);


    int n = 6;
    getCompo(g1,n);
    return 0;
}