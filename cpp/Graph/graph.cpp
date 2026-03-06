#include <iostream>
#include <vector>
#include <list>
#include <queue>

// A class to represent a graph.
class Graph {
private:
    int numVertices;
    // Adjacency list: array of lists of integers
    std::vector<std::list<int>> adj;

public:
    // Constructor
    Graph(int vertices) {
        this->numVertices = vertices;
        adj.resize(vertices);
    }

    // Function to add an edge to an undirected graph
    void addEdge(int src, int dest) {
        // Add an edge from src to dest.
        adj[src].push_back(dest);
        // Since the graph is undirected, add an edge from dest to src also
        adj[dest].push_back(src);
    }

    // BFS traversal from a given source vertex
    void BFS(int startVertex) {
        // Create a visited array and initialize all vertices as not visited
        std::vector<bool> visited(numVertices, false);

        // Create a queue for BFS
        std::queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[startVertex] = true;
        queue.push(startVertex);

        std::cout << "BFS starting from vertex " << startVertex << ": ";

        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex currentVertex.
            // If an adjacent has not been visited, then mark it visited and enqueue it.
            for (int adjacent : adj[currentVertex]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a graph with 7 vertices, similar to the one in your Java BFS example
    Graph g(7);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    // Perform BFS traversal starting from vertex 0
    g.BFS(0);

    return 0;
}