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
void util(graph &g, vector<int> &weight, vector<int>& parent,vector<bool>& inMst,int vertex)
{
    inMst[vertex] = true;

    // base case
    for(int i=0; i<inMst.size(); i++)
    {
        if(inMst[i] == false)
        break;
        else if(i == inMst.size()-1)
        return ;
    }

    for(auto i: g.adjList[vertex])
    {
        pair<int,int> temp = {vertex,i};
        // check if the weight of vertex->i is less than weight stored in weight
        if(g.weight[temp] < weight[i])
        {
            weight[i] = g.weight[temp];
            parent[i] = vertex;
        }
    }
    // get min weight from weight array
    int minWeight = INT_MAX;
    int flag;
    for(int i  = 0; i<weight.size(); i++)
    {
        if(weight[i] < minWeight && inMst[i] == false)
        {
            minWeight = weight[i];
            flag = i;
        }

    }

    util(g,weight,parent,inMst,flag);

}
void PrimsAlgo(graph &g)
{
    vector<int> weight(5,INT_MAX);
    vector<int> parent(5,-1);
    vector<bool> inMst(5,false);

    int source = 0;
    weight[source] = 0;
    util(g,weight,parent,inMst,source);

    for(int i=0; i<parent.size(); i++)
    {
        cout<<parent[i]<<" -> "<<i<<"  ";;
    }
}

int main()
{
    graph g1(0);
    g1.addEdge(0,1,2);
    g1.addEdge(0,3,6);
    g1.addEdge(1,2,3);
    g1.addEdge(1,3,8);
    g1.addEdge(1,4,5);
    g1.addEdge(4,2,7);

    PrimsAlgo(g1);
    return 0;

}