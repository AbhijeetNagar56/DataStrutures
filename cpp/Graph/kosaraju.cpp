#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class graph {
public:
    int V;
    vector<vector<int>> adj;

    graph(int v) {
        this->V = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topoSortUtil(int src, vector<bool>& vis, stack<int>& s, const vector<vector<int>>& currentAdj) {
        vis[src] = true;
        for (int nbr : currentAdj[src]) {
            if (!vis[nbr]) {
                topoSortUtil(nbr, vis, s, currentAdj);
            }
        }
        s.push(src);
    }
]
    void dfsUtil(int src, vector<bool>& vis, const vector<vector<int>>& currentAdj) {
        vis[src] = true;
        for (int nbr : currentAdj[src]) {
            if (!vis[nbr]) {
                dfsUtil(nbr, vis, currentAdj);
            }
        }
    }

    void kosaraju() {
        stack<int> stk;
        vector<bool> vis(V, false);

        // Step 1: Fill order in stack based on finishing times
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSortUtil(i, vis, stk, adj);
            }
        }

        // Step 2: Create Transpose Graph
        vector<vector<int>> transpose(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                transpose[v].push_back(u);
            }
        }

        // Step 3: Process vertices in reverse topological order
        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();

            if (!vis[u]) {
                dfsUtil(u, vis, transpose);
                sccCount++;
            }
        }

        cout << "Number of Strongly Connected Components: " << sccCount << endl;
    }
};

int main() {
    
    int V = 5;
    graph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); 
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Running Kosaraju's Algorithm..." << endl;
    g.kosaraju();

    return 0;
}