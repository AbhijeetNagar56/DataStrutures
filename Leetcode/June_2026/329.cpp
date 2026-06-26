class Solution {
private:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int i, int j, int pre, vector<vector<int>>& arr, vector<vector<bool>>& vis, vector<vector<int>>& memo) {
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || arr[i][j] <= pre) {
            return 0;
        }

        if(memo[i][j] != -1) return memo[i][j];

        vis[i][j] = true;
        int res = 0;
        for(auto& d: dir) {
            int ni = i+d[0];
            int nj = j+d[1];

            res = max(res, dfs(ni, nj, arr[i][j], arr, vis, memo));
        }
        vis[i][j] = false;
        memo[i][j] = 1 + res;
        return 1 + res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        int maxLen = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                int len = dfs(i, j, -1, matrix, vis, memo);
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
