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

    void bfs(int src) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for(auto nbr: adj[v]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    void dfsHelper(int src, vector<bool>& visited) {
        visited[src] = true;
        cout << src << " ";
        for(auto nbr: adj[src]) {
            if(!visited[nbr]) {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(int src) {
        vector<bool> visited(V, false);
        dfsHelper(src, visited);
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
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    cout << "BFS starting from vertex 0: ";
    g.bfs(0);
    cout << endl;
    cout << "DFS starting from vertex 0: ";
    g.dfs(0);
    cout << endl;
    
    return 0;
}