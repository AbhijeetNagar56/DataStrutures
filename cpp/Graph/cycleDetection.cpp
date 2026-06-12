#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;


class graph {
private:
    int V;
    list<int> *adj;
public:
    graph(int v) {
        V = v;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // detect cycle using dfs
    bool hasCycle(int src, int parent, vector<bool>& vis) {
        vis[src] = true;
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                if(hasCycle(nbr, src, vis)) return true;
            } else if(nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool detectCycle() {
        vector<bool> vis(V, false);
        return hasCycle(0, -1, vis);
    }


    // cycle detection using bfs
    bool hasCycle() {
        vector<bool> vis(V, false);
        queue<vector<int>> q;
        q.push({0, -1});
        vis[0] = true;

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            for(int n: adj[p[0]]) {
                if(!vis[n]) {
                    q.push({n, p[0]});
                    vis[n] = true;
                } else if(n != p[1]) {
                    return true;
                }
            }
        }

        return false;

    }

    void print() {
        for(int i=0; i<V; i++) {
            cout << i << ": ";
            for(auto nbr: adj[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    if(g.hasCycle()) {
        cout << "has cycle";
    } else {
        cout << "not having cycle";
    }
    cout << endl;

    
    return 0;
}