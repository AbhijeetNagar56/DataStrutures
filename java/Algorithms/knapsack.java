import java.util.Arrays;
import java.util.Comparator;

class Item {
    int profit;
    int weight;
    double ratio;
    int index;

    public Item(int profit, int weight, int index) {
        this.profit = profit;
        this.weight = weight;
        this.ratio = (double) profit / weight;
        this.index = index;
    }
}

public class knapsack {
    public static double profit(int pf[], int wt[], int capacity, int n) {
        
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            items[i] = new Item(pf[i], wt[i], i);
        }

        Arrays.sort(items, Comparator.comparingDouble((Item item) -> item.ratio).reversed());

        double totalProfit = 0.0;
        int currentCapacity = capacity;

        for (Item item : items) {
            
            if (currentCapacity >= item.weight) {
                currentCapacity -= item.weight;
                totalProfit += item.profit;
            } 
            else {
                double fraction = (double) currentCapacity / item.weight;
                totalProfit += fraction * item.profit;
                
                currentCapacity = 0; 
                break;
            }
        }

        return totalProfit;
    }

    public static void main(String args[]) {
        int[] pf = {60, 100, 120};
        int[] wt = {10, 20, 30};
        int capacity = 50;
        int n = pf.length;

        double maxProfit = profit(pf, wt, capacity, n);
        System.out.println("Maximum Profit: " + maxProfit);
    }
}