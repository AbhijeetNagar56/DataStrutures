#include <stdio.h>
#define MAX 8


int graph[MAX][MAX] = {
    // A B C D E F G H
    {0,0,0,1,0,0,0,0}, // A
    {1,0,1,0,1,0,0,0}, // B
    {0,0,0,0,1,0,0,0}, // C
    {0,0,1,0,0,0,1,0}, // D
    {1,0,0,0,0,0,0,0}, // E
    {0,0,1,0,0,0,0,0}, // F
    {0,0,0,0,0,1,0,1}, // G
    {0,0,0,0,0,0,0,0}  // H
};

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

// Stack for DFS
int stack[MAX], top = -1;


char nodeLabel(int i) {
    return 'A' + i;
}

// BFS Traversal
void bfs(int start) {
    int visited[MAX] = {0};
    front = rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != rear) {
        int current = queue[++front];
        printf("%c ", nodeLabel(current));

        for (int i = 0; i < MAX; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Traversal
void dfsRecursive(int current, int visited[]) {
    visited[current] = 1;
    printf("%c ", nodeLabel(current));

    for (int i = 0; i < MAX; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfsRecursive(i, visited);
        }
    }
}

void dfs(int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfsRecursive(start, visited);
    printf("\n");
}

int main() {
    int startNode = 1; // starting with 'B'
    bfs(startNode);
    dfs(startNode);
    return 0;
}
