package graph;
import java.util.LinkedList;


public class graphTraversal {
    public static void bfs(int[][] adjMatrix) {
        int n = adjMatrix.length;
        boolean[] visited = new boolean[n];

        LinkedList<Integer> queue = new LinkedList<Integer>();

        int startNode = 0;
        visited[startNode] = true;
        queue.add(startNode);

        System.out.println("BFS Traversal:");

        while (queue.size() != 0) {

            int currentVertex = queue.poll();
            System.out.print(currentVertex + " ");

            for (int i = 0; i < n; i++) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
        System.out.println();
    }

    public static void dfs(int[][] adjMatrix) {
        int n = adjMatrix.length;
        boolean[] visited = new boolean[n];

        System.out.println("\nDFS Traversal:");

        dfsRecursive(0, adjMatrix, visited);
        System.out.println();
    }

    private static void dfsRecursive(int currentVertex, int[][] adjMatrix, boolean[] visited) {

        visited[currentVertex] = true;
        System.out.print(currentVertex + " ");

        int n = adjMatrix.length;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                dfsRecursive(i, adjMatrix, visited);
            }
        }
    }

    public static void addEdge(int[][] adj, int s, int d) {
        if (s < 0 || s >= adj.length || d < 0 || d >= adj.length) {
            System.out.println("invalid edge");
            return;
        }
        adj[s][d] = 1;
        adj[d][s] = 1; // undirected graph
    }

    public static void main(String args[]) {
        int[][] adj = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 0, 2);

        bfs(adj);
        dfs(adj);
    }
}
