public class binaryKnapsack {
    static int knapsack(int wt[], int val[], int W, int n) {
        if (n == 0 || W == 0) {
            return 0;
        }
        if (wt[n - 1] <= W) {
            return Math.max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                    knapsack(wt, val, W, n - 1));
        } else if (wt[n - 1] > W) {
            return knapsack(wt, val, W, n - 1);
        }
        return 0;
    }
    public static void main(String[] args) {
        int weights[] = { 1, 2, 3 };
        int values[] = { 10, 15, 40 };
        int capacity = 6;
        int n = values.length;
        System.out.println("Maximum value in Knapsack = " + knapsack(weights, values, capacity, n));
    }
}
