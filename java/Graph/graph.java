
class graph {
    int gp[][] = new int[10][10];
    int vertex;
    graph(int v) {
        this.vertex = v;
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                this.gp[i][j] = 0;
            }
        }
    }

    public void printGraph() {
        for(int i = 0; i < this.vertex; i++) {
            for(int j = 0; j < this.vertex; j++) {
                System.out.print(this.gp[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void add(int s, int d) {
        if(s < 1 || s >= this.vertex || d < 1 || d >= this.vertex) {
            System.out.println("Not a valid edge!");
        } 
        // assume bidirected graph
        this.gp[s-1][d-1] = 1;
        this.gp[d-1][s-1] = 1;

    }
 

}


public class graph {
    public static void main(String args[]) {
        graph g1 = new graph(3);
        g1.add(1, 2);
        g1.printGraph();
        System.out.println("heleo");
    }
}