import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Comparator;

public class PrimsMST {

    public static double findMSTWeight(int n, int[][] graph) {
        
        int[] key = new int[n];
        boolean[] mstSet = new boolean[n];
        
        Arrays.fill(key, Integer.MAX_VALUE);
        

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        int startVertex = 0;
        key[startVertex] = 0;
        pq.add(new int[]{0, startVertex}); 

        double totalMSTWeight = 0.0;
        
        while (!pq.isEmpty()) {
            
            int[] minEntry = pq.poll();
            int w = minEntry[0];
            int u = minEntry[1];

            if (mstSet[u]) {
                continue;
            }

            mstSet[u] = true;
            totalMSTWeight += w;

            for (int v = 0; v < n; v++) {
                int weight_uv = graph[u][v];

                if (weight_uv > 0 && !mstSet[v] && weight_uv < key[v]) {
                    
                    key[v] = weight_uv;
                    
                    pq.add(new int[]{weight_uv, v});
                }
            }
        }
        
        int verticesInMST = 0;
        for (boolean inSet : mstSet) {
            if (inSet) verticesInMST++;
        }
        
        if (verticesInMST != n) {
             System.out.println("Warning: Graph is not connected. MST cannot span all vertices.");
        }

        return totalMSTWeight;
    }

    public static void main(String[] args) {
        int n = 5;

        
        int[][] graph = {
            // A  B  C  D  E
            {0, 2, 4, 0, 0}, // A
            {2, 0, 1, 7, 0}, // B
            {4, 1, 0, 5, 3}, // C
            {0, 7, 5, 0, 6}, // D
            {0, 0, 3, 6, 0}  // E
        };

        double mstWeight = findMSTWeight(n, graph);

        System.out.println("--- Simplified Prim's Algorithm (MST) ---");
        System.out.println("Total Vertices (n): " + n);

        System.out.println("Total Weight of the Minimum Spanning Tree (MST): " + mstWeight);
    }
} 
