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

void getSet(vector<int> &parent, vector<int> &rank) {
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int getParent(vector<int> &parent, int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    } else {
        return parent[vertex] = getParent(parent, parent[vertex]);
    }
}

void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = getParent(parent, u);
    v = getParent(parent, v);

    if (rank[v] < rank[u]) {
        parent[v] = u;
    } else if (rank[u] < rank[v]) {
        parent[u] = v;
    } else {
        parent[u] = v;
        rank[v]++;
    }
}

void Kruskal(graph &g, int n) {
    vector<int> parent(n);
    vector<int> rank(n);
    getSet(parent, rank);

    vector<pair<int,pair<int, int>>> sortedWeight; // Store edges and their weights
    for (auto edge : g.weight) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        sortedWeight.push_back({w, {u, v}});
    }

    sort(sortedWeight.begin(), sortedWeight.end());

    int totalWeightOfMST = 0;
    for (auto edge : sortedWeight) {
        int u = edge.second.first;
        int v = edge.second.second;

        if (getParent(parent, u) != getParent(parent, v)) {
            totalWeightOfMST += edge.first;
            makeUnion(u, v, parent, rank);
        }
    }
    cout << "Weight of MST = " << totalWeightOfMST;
}

int main() {
    graph g1(0);
    g1.addEdge(0, 1, 2);
    g1.addEdge(1, 2, 3);
    g1.addEdge(2, 0, 1);

    int n = 3;
    Kruskal(g1, n);
    cout << " finish";
    return 0;
}
