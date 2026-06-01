#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int V;
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (auto nbr : l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    printf("Graph adjacency list:\n");
    g.printGraph();
    return 0;
}