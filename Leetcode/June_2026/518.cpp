class Solution {
private:
    int dfs(int i, int amt, vector<int>& arr, vector<vector<int>>& memo) {
        if(amt == 0) return 1;
        if(i>=arr.size() || amt < 0) return 0;
        if(memo[i][amt] != -1) {
            return memo[i][amt];
        }
        memo[i][amt] = dfs(i+1, amt, arr, memo) + dfs(i, amt-arr[i], arr, memo);
        return memo[i][amt];
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> memo(coins.size()+1, vector<int>(amount+1, -1));
        return dfs(0, amount, coins, memo);
    }
};