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
            pair<int,int> p = {u,v};
            this->weight[p] = weight;
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
void Dijk(graph &g, int s)
{
    vector<int> dis(5,INT_MAX);
    dis[s] = 0;

    set<pair<int,int>> S;
    S.insert(make_pair(dis[s], s));

    while(!S.empty())
    {
        pair<int,int> temp = *(S.begin());
        S.erase(S.begin());
        for(auto i: g.adjList[temp.second])
        {
            pair<int,int> temp1 = {temp.second,i};
            if(temp.first + g.weight[temp1] < dis[i])
            {
                dis[i] = temp.first + g.weight[temp1];
                S.insert(make_pair(dis[i],i));
            }
        }
    }

    for(auto i: dis)
    cout<<i<<" ";
}
int main()
{
    graph g1(0);
    g1.addEdge(1,2,3);
    g1.addEdge(1,0,7);
    g1.addEdge(1,3,5);
    g1.addEdge(1,4,1);
    g1.addEdge(2,0,1);
    g1.addEdge(0,3,2);
    g1.addEdge(3,4,7);

    Dijk(g1,0);
    
}