#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int src, int dst, int wt) {
        this->u = src;
        this->v = dst;
        this->w = wt;
    }

    bool operator<(const Edge &other) const {
        return this->w < other.w;
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;
    vector<int> par, rank;
    
    Graph(int V) {
        this->V = V;
        for(int i = 0; i < V; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    void kruskal() {
        sort(edges.begin(), edges.end());
        int mstCost = 0;
        vector<Edge> mstEdges;

        for(auto e : edges) {
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV) {
                unionByRank(e.u, e.v);
                mstCost += e.w;
                mstEdges.push_back(e);
            }
        }

        cout << "MST cost: " << mstCost << endl;
        cout << "MST edges:" << endl;
        for(const auto& edge : mstEdges) {
            cout << edge.u << " - " << edge.v << " (weight: " << edge.w << ")" << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 4, 6);
    g.addEdge(3, 4, 4);
    g.addEdge(1, 3, 15);

    g.kruskal();

    return 0;
}