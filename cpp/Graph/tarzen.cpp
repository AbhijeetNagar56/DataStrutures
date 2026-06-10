#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
public:
    Graph(int n)
        : V(n), adj(n), disc(n, 0), low(n, 0), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> findCriticalConnections() {
        for (int i = 0; i < V; ++i) {
            if (disc[i] == 0) {
                dfs(i, -1);
            }
        }
        return bridges;
    }

private:
    int V;
    vector<vector<int>> adj;
    vector<int> disc;
    vector<int> low;
    vector<vector<int>> bridges;
    int timer;

    void dfs(int u, int parent) {
        disc[u] = low[u] = ++timer;

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            if (disc[v] == 0) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};

int main() {
    int V = 5;
    Graph g(V);
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    for (auto &e : edges) {
        g.addEdge(e[0], e[1]);
    }

    vector<vector<int>> critical = g.findCriticalConnections();

    cout << "Critical connections (bridges):\n";
    for (auto &edge : critical) {
        cout << edge[0] << " - " << edge[1] << '\n';
    }

    return 0;
}