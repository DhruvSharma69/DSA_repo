#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    map<int,list<int>> adjList;
    map<pair<int,int>, int> weight;
    bool directed;
    graph(bool type)
    {
        directed = type;
    }
   void addEdge(int v, int u, int weight)//an edge that joins v to u if directed = 1 and also join u to v if d = 0 
    {
        adjList[v].push_back(u);
        pair<int,int> p = {v,u};
       this->weight[p] = weight;
        if(directed == 0)
        {
            adjList[u].push_back(v);
        }
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
void topoUtil(graph &g, stack<int> &st, map<int,bool> &visited,int vertex )
{
    visited[vertex] = true;

    for(auto i: g.adjList[vertex])
    {
        if(visited[i] != true)
        {
            topoUtil(g,st,visited,i);
        }
    }
    st.push(vertex);
}
vector<int> topoSort(graph &g)
{
    map<int,bool> visited;
    stack<int> st;
    for(int i=0; i<6; i++)
    {
        if(!visited[i])
        {
            topoUtil(g,st,visited,i);
        }
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
void shortestPath(graph &g, int s)
{
    vector<int> sortedGraph = topoSort(g);
    vector<int> Weights(6, INT_MAX);
    Weights[s] = 0;
    for(int w = 0; w<Weights.size();w++)
    {
        if(Weights[w] != INT_MAX)
        for(auto i: g.adjList[w])
        {
            pair<int,int> temp = {w,i};
            // Weights[i] = g.weight[temp];
            if(Weights[w] + g.weight[temp] < Weights[i])
            Weights[i] = Weights[w] + g.weight[temp];
        }
    }
    
    // print the answer
    for(auto i: Weights)
    {
        cout<<i<<"  ";
    }
}
int main()
{
    graph g1(1);
    g1.addEdge(0,1,5);
    g1.addEdge(0,2,3);
    g1.addEdge(1,2,2);
    g1.addEdge(1,3,6);
    g1.addEdge(2,3,7);
    g1.addEdge(2,4,4);
    g1.addEdge(3,4,-1);
    g1.addEdge(4,5,-2);
    g1.addEdge(2,5,2);
    
   shortestPath(g1,1);
    return 0;
}

 