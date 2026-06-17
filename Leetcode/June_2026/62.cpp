// class Solution {
// private:
//     int r, c;

//     int dfs(int i, int j) {
//         if(i>=r || j>=c) return 0;

//         if(i==r-1 && j==c-1) {
//             return 1;
//         }

//         return dfs(i+1, j) + dfs(i, j+1);

//     }
// public:
//     int uniquePaths(int m, int n) {
//         r=m;
//         c=n;

//         return dfs(0, 0);

//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];

    }
};
