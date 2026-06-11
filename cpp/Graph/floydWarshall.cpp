#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int v;
    int wt;
    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

class graph {
public:
    int V;
    vector<vector<Edge>> adj;
    
    graph(int v) {
        this->V = v;
        adj.resize(v);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(Edge(v, w)); // directed weighted edge
    }

    void floydWarshall() {
        const int INF = 1e9;

        vector<vector<int>> dist(V, vector<int>(V, INF));

        for (int i = 0; i < V; i++) {
            dist[i] [i] = 0;
        }

        for (int u = 0; u < V; u++) {
            for (const auto& e : adj[u]) {
                dist[u] [e.v] = e.wt;
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // If path i->k and k->j exists and is shorter than current i->j
                    if (dist[i] [k] != INF && dist[k] [j] != INF) {
                        dist[i] [j] = min(dist[i] [j], dist[i] [k] + dist[k] [j]);
                    }
                }
            }
        }

        cout << "Shortest Path Matrix:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "From " << i << ": ";
            for (int j = 0; j < V; j++) {
                if (dist[i] [j] == INF) {
                    cout << "INF ";
                } else {
                    cout << "To " << j << " (" << dist[i] [j] << ") ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4;
    graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 2);

    g.floydWarshall();

    return 0;
}