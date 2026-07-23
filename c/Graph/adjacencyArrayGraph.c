#include <stdio.h>
#include <stdlib.h>

#define MAX 10


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* adjArray[MAX];
    int numVertices;
} Graph;


Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adjArray[i] = NULL;
    }
}


void addEdge(Graph* g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid edge!\n");
        return;
    }
    Node* newNode = createNode(dest);
    newNode->next = g->adjArray[src];
    g->adjArray[src] = newNode;
    
    // Assuming Undirected
    newNode = createNode(src);
    newNode->next = g->adjArray[dest];
    g->adjArray[dest] = newNode;
}

void displayGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        Node* temp = g->adjArray[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    Graph G;
    initGraph(&G, vertices);
    
    addEdge(&G, 0, 1);
    addEdge(&G, 0, 4);
    addEdge(&G, 1, 2);
    addEdge(&G, 1, 3);
    addEdge(&G, 1, 4);
    addEdge(&G, 2, 3);
    addEdge(&G, 3, 4);
    
    displayGraph(&G);
    return 0;
}
