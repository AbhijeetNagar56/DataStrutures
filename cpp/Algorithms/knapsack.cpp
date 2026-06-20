#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Struct to represent an item
struct Item {
    int wt;
    int pf;
    Item(int w, int p) {
        this->wt = w;
        this->pf = p;
    }
};

// 1. FRACTIONAL KNAPSACK (Greedy Approach using Max-Heap)
double frac_knapsack(int n, int m, vector<Item>& a) {
    // Max-heap stores pairs of {profit/weight ratio, index}
    priority_queue<pair<double, int>> pq;
    
    for(int i = 0; i < n; i++) {
        // Cast to double to prevent integer division truncating fractions
        double ratio = (double)a[i].pf / a[i].wt;
        pq.push({ratio, i});
    }

    double max_profit = 0.0;
    int current_weight = 0;

    while(!pq.empty() && current_weight < m) {
        auto top = pq.top();
        pq.pop();
        
        int idx = top.second;

        // If the item can be taken as a whole
        if (current_weight + a[idx].wt <= m) {
            current_weight += a[idx].wt;
            max_profit += a[idx].pf;
        } 
        // If we can only take a fraction of the item
        else {
            int remaining_capacity = m - current_weight;
            max_profit += a[idx].pf * ((double)remaining_capacity / a[idx].wt);
            break; // Knapsack is full
        }
    }
    return max_profit;
}

// 2. 0/1 KNAPSACK: RECURSIVE APPROACH
int zero_one_knapsack_rec(int index, int capacity, vector<Item>& a) {
    // Base Case: No items left or knapsack is full
    if (index < 0 || capacity == 0) {
        return 0;
    }

    // If item weight is more than remaining capacity, we must skip it
    if (a[index].wt > capacity) {
        return zero_one_knapsack_rec(index - 1, capacity, a);
    }

    // Otherwise, return maximum of taking the item vs. leaving it
    int take = a[index].pf + zero_one_knapsack_rec(index - 1, capacity - a[index].wt, a);
    int leave = zero_one_knapsack_rec(index - 1, capacity, a);

    return max(take, leave);
}

// 3. 0/1 KNAPSACK: DYNAMIC PROGRAMMING (Bottom-Up / Tabulation)
int zero_one_knapsack_dp(int n, int m, vector<Item>& a) {
    // Create a DP table of size (n + 1) x (m + 1) initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= m; w++) {
            // Note: a[i-1] corresponds to the i-th item due to 0-based indexing in vector
            if (a[i - 1].wt <= w) {
                dp[i][w] = max(a[i - 1].pf + dp[i - 1][w - a[i - 1].wt], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][m];
}

int main() {
    int n = 3;
    int m = 50; // Changed capacity to 50 for a classic standard testing scenario
    
    vector<Item> arr;
    arr.push_back(Item(10, 60));
    arr.push_back(Item(20, 100));
    arr.push_back(Item(30, 120));

    cout << "--- Knapsack Execution Results ---" << endl;
    cout << "Fractional Knapsack Max Profit: " << frac_knapsack(n, m, arr) << endl;
    cout << "0/1 Knapsack (Recursive) Max Profit: " << zero_one_knapsack_rec(n - 1, m, arr) << endl;
    cout << "0/1 Knapsack (DP Tabulation) Max Profit: " << zero_one_knapsack_dp(n, m, arr) << endl;

    return 0;
}